pub struct Solution {}

use std::cmp::max;

impl Solution {
    pub fn stone_game_v(stone_values: Vec<i32>) -> i32 {
        let n = stone_values.len();
        // prefix sum
        let mut prefix_sum = vec![0; n + 1];

        for i in 0..n {
            prefix_sum[i+1] = stone_values[i] + prefix_sum[i];
        }

        let mut table = vec![vec![0; n + 1]; n +1];

        for i in (0..n).rev() {
            for j in i..n {
                if i >= j { continue; }

                let mut best = 0;

                let mut k = i + 1;
                while k <= j {
                    let left_val = prefix_sum[k] - prefix_sum[i];
                    let right_val = prefix_sum[j + 1] - prefix_sum[k];

                    if left_val > right_val {
                        best = max(best, right_val + table[k][j]);
                    } else if left_val < right_val {
                        best = max(best, left_val + table[i][k - 1]);
                    } else {
                        best = max(best, max(left_val + table[i][k - 1],right_val + table[k][j]))
                    }

                    k += 1;
                }

                table[i][j] = best;
            }
        }

        return table[0][n - 1];
    }
}