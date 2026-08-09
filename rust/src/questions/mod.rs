pub mod q1406_stone_game_iii;

pub fn run() {
    test(vec![1,2,3,7], "Bob");
    test(vec![1,2,3,-9], "Alice");
    test(vec![1,2,3,6], "Tie");

    println!("Passed all tests!");
}

fn test(input: Vec<i32>, answer: &str) {
    println!("stone_value: {input:?}, answer = {answer}");
    let res = q1406_stone_game_iii::Solution::stone_game_iii(input);
    assert_eq!(res, String::from(answer));
}
