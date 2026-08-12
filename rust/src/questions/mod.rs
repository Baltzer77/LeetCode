pub mod q32_longest_valid_parentheses;

pub fn run() {
    test("(()", 2);
    test(")()())",4);
    test("()(()",2);
    test(")(((((()())()()))()(()))(",22);
    test("",0);
    test("(()()",4);
    test("(()()(())((",8);
    test(")))(((()()",4);
    test("()((())()",6);

    println!("Passed all tests!");
}

fn test(input: &str, answer: i32) {
    println!("input: {input:?}, answer = {answer}");
    let res = q32_longest_valid_parentheses::Solution::longest_valid_parentheses(String::from(input));
    assert_eq!(res, answer);
}
