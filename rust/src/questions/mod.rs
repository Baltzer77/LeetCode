pub mod q65_valid_number;

pub fn run() {
    test("123", true);
    test("e", false);
    test(".", false);
    test("-1E+3", true);
    test("1E2.0", false);
    test(".e2", false);
    test("inf", false);
    test("+", false);
    test("+123.0e-7809", true);
    test(".1", true);

    println!("Passed all tests!");
}

fn test(input: &str, answer: bool) {
    println!("input: {input:?}, answer = {answer}");
    let res = q65_valid_number::Solution::is_number(String::from(input));
    assert_eq!(res, answer);
}
