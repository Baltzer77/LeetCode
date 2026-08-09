pub mod q1510_stone_game_iv;

pub fn run() {
    test(1, true);
    test(2, false);
    test(4, true);

    println!("Passed all tests!");
}

fn test(input: i32, answer: bool) {
    println!("stone_value: {input:?}, answer = {answer}");
    let res = q1510_stone_game_iv::Solution::winner_square_game(input);
    assert_eq!(res, answer);
}
