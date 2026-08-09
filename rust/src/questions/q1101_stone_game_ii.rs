pub struct Solution {}

use std::cmp::max;

impl Solution {
    pub fn stone_game_ii(piles: Vec<i32>) -> i32 {
        let n = piles.len();
        // prefix sum
        let mut prefix_sum = vec![0; n + 1];

        for i in 0..n {
            prefix_sum[i+1] = piles[i] + prefix_sum[i];
        }

        if n <= 2 {
            return prefix_sum[n];
        }

        let mut table = vec![vec![(0,0); n + 1]; n + 1];

        for i in (0..n).rev() {
            for m in (1..=n).rev() {

                let mut best = (0, 0);
                for x in 1..=m*2 {
                    if i + x > n {
                        continue;
                    }

                    let table_val = table[i + x][max(m, x)];

                    let val = prefix_sum[i + x] - prefix_sum[i] + table_val.1;

                    if best.0 <= val {
                        best = (val, table_val.0);
                    }
                }
                println!("i = {i}, m = {m}, best = {best:?}");
                table[i][m] = best;
            }
        }
        for i in 0..n {
            for j in 1..n {
                print!("({},{}) ", table[i][j].0, table[i][j].1);
            }
            println!();
        }

        return table[0][1].0;
    }
}