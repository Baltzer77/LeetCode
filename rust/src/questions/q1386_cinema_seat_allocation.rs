struct Solution {}

pub fn run_tests() {
    test(3,vec![vec![1,2],vec![1,3],vec![1,8],vec![2,6],vec![3,1],vec![3,10]], 4);
    test(2,vec![vec![2,1],vec![1,8],vec![2,6]], 2);
    test(4,vec![vec![4,3],vec![1,4],vec![4,6],vec![1,7]],4);


    println!("Passed all tests!");
}

fn test(input1 : i32, input2: Vec<Vec<i32>>, answer: i32) {

    println!("input1: {input1:?}, input2: {input2:?}, answer = {answer:?}");

    let res = Solution::max_number_of_families(input1, input2);
    assert_eq!(res, answer);
}

use std::collections::HashMap;

impl Solution {
    pub fn max_number_of_families(n: i32, reserved_seats: Vec<Vec<i32>>) -> i32 {
        let mut hash : HashMap<i32, u16> = HashMap::with_capacity(reserved_seats.len());

        let mut res = n << 1;

        for s in &reserved_seats {
            if let [row, seat] = s[0..2] {
                let cur_row = hash.entry(row).or_insert(0);
                let new_row = *cur_row | (1 << (seat - 1));

                if Self::count_groups(*cur_row) > Self::count_groups(new_row) {
                    res -= 1;
                }

                *cur_row = new_row;
            } else {
                unreachable!();
            }
        }

        //for i in (0..n) {
            //let row = hash.entry(i + 1).or_insert(0);

            //println!("{:010b}", *row);
        //}

        res
    }

    #[inline]
    fn count_groups(row: u16) -> i32 {
        const LEFT_MASK: u16 = 0b0000_0000_0001_1110;
        const RIGHT_MASK: u16 = 0b0000_0001_1110_0000;
        const MIDDLE_MASK: u16 = 0b0000_0000_0111_1000;
        const DUAL_MASK: u16 = LEFT_MASK | RIGHT_MASK;

        if row & DUAL_MASK == 0 {
            2
        } else if row & (LEFT_MASK) == 0 || row & RIGHT_MASK == 0 || row & MIDDLE_MASK == 0 {
            1
        } else {
            0
        }
    }
}