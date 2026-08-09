pub struct Solution {}

impl Solution {
    pub fn stone_game(piles: Vec<i32>) -> bool {
        let n = piles.len();

        let mut table = vec![vec![(0,0); n + 1]; n + 1];

        for i in (0..n-1).rev() {
            for j in 1..n {
                if i > j {
                    continue;
                }

                let left_val = table[i +1][j]; 
                let right_val = table[i][j - 1];

                let left_new_val = left_val.1 + piles[i];
                let right_new_val = right_val.1 + piles[j];

                if left_new_val > right_new_val {
                    table[i][j] = (left_new_val, left_val.0);
                } else {
                    table[i][j] = (right_new_val, right_val.0);
                }
            }
        }

        return table[0][n-1].0 > table[0][n-1].1;
    }
}