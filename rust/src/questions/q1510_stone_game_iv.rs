pub struct Solution {}

impl Solution {
    pub fn winner_square_game(n: i32) -> bool {
        let n = n as usize;
        let mut table = vec![false; n +1];

        for i in 1..=n {
            for j in 1..=i {
                if j * j > i {break;}

                let index:usize = i - j*j;

                if table[index] == false {
                    table[i] = true;
                    break;
                }
            }
        }

        return table[n];
    }
}