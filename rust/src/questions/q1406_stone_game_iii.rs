pub struct Solution {}

impl Solution {
    pub fn stone_game_iii(stone_values: Vec<i32>) -> String {
        let n = stone_values.len();
        // prefix sum
        let mut prefix_sum = vec![0; n + 1];

        for i in 0..n {
            prefix_sum[i+1] = stone_values[i] + prefix_sum[i];
        }

        let mut table = vec![(0, 0); n + 3];

        for i in (0..n).rev() {
            let mut best = (i32::MIN, i32::MIN); 
            for j in 1..=3 {
                if i + j > n { continue; }

                let stone_val = prefix_sum[i + j] - prefix_sum[i];
                let val = stone_val + table[i + j].1;
                if val > best.0 {
                    best = (val, table[i+j].0);
                }

                table[i] = best;
            }
        }

        if table[0].0 > table[0].1 {
            return String::from("Alice");
        } else if table[0].0 < table[0].1 {
            return String::from("Bob");
        } else {
            return String::from("Tie");
        }
    }
}