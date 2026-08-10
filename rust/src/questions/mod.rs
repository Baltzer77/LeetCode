pub mod q1686_stone_game_vi;

pub fn run() {
    test(vec![1,3], vec![2,1], 1);
    test(vec![1,2], vec![3,1], 0);
    test(vec![2,4,3], vec![1,6,7], -1);

    println!("Passed all tests!");
}

fn test(input1: Vec<i32>, input2: Vec<i32>, answer: i32) {
    println!("alice_values: {input1:?}, bob_values: {input2:?} answer = {answer}");
    let res = q1686_stone_game_vi::Solution::stone_game_vi(input1, input2);
    assert_eq!(res, answer);
}
