struct Solution {}

pub fn run_tests() {
    test(vec![5,3,1,4,2], 6);
    test(vec![7,90,5,1,100,10,10,2], 122);

    println!("Passed all tests!");
}

fn test(input : Vec<i32>, answer: i32) {
    println!("input: {input:?}, answer = {answer:?}");
    let res = Solution::stone_game_vii(input);
    assert_eq!(res, answer);
}

// solution from here on

use std::cmp::max;
use std::cmp::min;

impl Solution {
    pub fn stone_game_vii(stone_values : Vec<i32>) -> i32 {
        let n = stone_values.len();
        let parity = n & 1; // alice will always have the turns with even or odd length

        let mut prefix_sum = vec![0i32; n + 1];

        for i in 0..n {
            prefix_sum[i + 1] = prefix_sum[i] + stone_values[i];
        }

        let mut row  = vec![0i32; n];
        let mut prev_row  = vec![0i32; n];

        for i in (0..n).rev() {
            for j in i..n {
                if i >= j { continue; }
                let alice_turn = parity == (j - i + 1) & 1;

                let left_val = prev_row[j]; 
                let right_val = row[j - 1];

                let left_sum = prefix_sum[j + 1] - prefix_sum[i + 1];
                let right_sum = prefix_sum[j] - prefix_sum[i];

                if alice_turn {
                    row[j] = max(left_val + left_sum, right_val + right_sum);
                } else {
                    row[j] = min(left_val - left_sum, right_val - right_sum);
                }

            }
            std::mem::swap(&mut row, &mut prev_row);
        }

        prev_row[n - 1]
    }
}