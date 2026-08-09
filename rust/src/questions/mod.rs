pub mod q877_stone_game;

pub fn run() {
    test(vec![5,3,4,5], true);
    test(vec![3,7,2,3], true);

    println!("Passed all tests!");
}

fn test(piles: Vec<i32>, answer: bool) {
    println!("piles: {piles:?}, answer = {answer}");
    let res = q877_stone_game::Solution::stone_game(piles);
    assert_eq!(res, answer);
}
