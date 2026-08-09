pub mod q1101_stone_game_ii;

pub fn run() {
    test(vec![2,7,9,4,4], 10);
    test(vec![1,2,3,4,5,100], 104);
    test(vec![1], 1);
    test(vec![94,65,70,79,91,80,21,67,84,64,34,22,14,10,72], 479);
    println!("Passed all tests!");
}

fn test(piles: Vec<i32>, answer: i32) {
    println!("piles: {piles:?}, answer = {answer}");
    let res = q1101_stone_game_ii::Solution::stone_game_ii(piles);
    assert_eq!(res, answer);
}
