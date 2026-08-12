pub struct Solution {}

use std::cmp::max;

impl Solution {
    pub fn longest_valid_parentheses(s: String) -> i32 {
        let n = s.len();
        let s_bytes = s.as_bytes();
        
        if n <= 1 { return 0; }

        let mut left_stack: Vec<usize> = Vec::new();

        let mut best = 0;
        let mut i = 0;
        let mut last_wrong = 0;
        while i < n {
            while i < n && s_bytes[i] == b'(' {
                left_stack.push(i);
                i += 1;
            }

            while i < n && s_bytes[i] == b')' {
                if !left_stack.is_empty() {
                    left_stack.pop();
                    
                    let start = if left_stack.is_empty() {last_wrong} else {max(*left_stack.last().unwrap() + 1, last_wrong)};

                    best = max(best, i - start + 1);
                } else {
                    last_wrong = i + 1;
                }

                i += 1;
            }
        }

        return best as i32;
    }
}