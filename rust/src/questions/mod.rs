pub mod q1563_stone_game_v;

pub fn run() {
    test(vec![6,2,3,4,5,5], 18);
    test(vec![7,7,7,7,7,7,7], 28);
    test(vec![4], 0);
    test(vec![2, 1, 1], 3);

    println!("Passed all tests!");
}

fn test(input: Vec<i32>, answer: i32) {
    println!("stone_value: {input:?}, answer = {answer}");
    let res = q1563_stone_game_v::Solution::stone_game_v(input);
    assert_eq!(res, answer);
}
