struct Solution {}

pub fn run_tests() {
    test(vec![2, 1], true);
    test(vec![2], false);
    test(vec![5,1,2,4,3], false);

    println!("Passed all tests!");
}

fn test(input : Vec<i32>, answer: bool) {
    println!("input: {input:?}, answer = {answer:?}");
    let res = Solution::stone_game_ix(input);
    assert_eq!(res, answer);
}

// solution from here on
impl Solution {
    pub fn stone_game_ix(stones: Vec<i32>) -> bool {
        let n = stones.len();
        let mut count = vec![0i32; 3];

        for i in 0..n {
            let index = (stones[i] % 3) as usize;
            count[index] += 1;
        }

        let mut stones_processed = vec![0i32; 3];
        let should_flip = count[0] % 2 == 1;

        let mut simulate = |start  : i32| {
            stones_processed = vec![0i32; 3];
            stones_processed[start as usize] = 1;

            let mut remainder = start;
            let mut turn = true;

            loop {
                if stones_processed[remainder as usize] >= count[remainder as usize] {
                    if stones_processed[(3 - remainder) as usize] < count[(3 - remainder) as usize] {
                        return turn ^ should_flip;
                    } 
                    return false;
                } else {
                    stones_processed[remainder as usize] += 1;
                    remainder = (remainder + remainder) % 3;
                    turn = !turn;
                }
            }
        };

        if count[2] > 0 && simulate(2) {
            return true;
            
        }

        if count[1] > 0 && simulate(1) {
            return true;
        }

        false
    }
}