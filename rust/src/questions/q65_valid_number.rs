pub struct Solution {}

enum Token {
    Digit,
    Dot,
    Sign,
    Exponent,
    Unknown,
    End
}

impl Solution {
    pub fn is_number(s: String) -> bool {
        let s_bytes = s.as_bytes();
        let n = s_bytes.len();

        let mut i = 0;
        let mut state = 0;
        while i <= n {
            let token = Self::token_of_index(i, s_bytes);

            match (state, token) {
                (0, Token::Sign) => state = 1,    
                (0, Token::Digit) => state = 2,
                (0, Token::Dot) => state = 8,

                (1, Token::Dot) => state = 8,
                (1, Token::Digit) => state = 2,

                (2, Token::Digit) => state = 2,
                (2, Token::Dot) => state = 3,
                (2, Token::Exponent) => state = 5,
                (2, Token::End) => return true,

                (3, Token::Digit) => state = 4,
                (3, Token::Exponent) => state = 5,
                (3, Token::End) => return true,

                (4, Token::Digit) => state = 4,
                (4, Token::Exponent) => state = 5,
                (4, Token::End) => return true,

                (5, Token::Sign) => state = 6,
                (5, Token::Digit) => state = 7,

                (6, Token::Digit) => state = 7,

                (7, Token::Digit) => state = 7,
                (7, Token::End) => return true,

                (8, Token::Digit) => state = 4,

                _ => return false,
            }
            i += 1;
        }

        return false; // should never happen
    }

    fn token_of_index(index: usize, s: &[u8]) -> Token {
        match s.get(index) {
            Some(b'0'..=b'9') => Token::Digit,
            Some(b'.') => Token::Dot,
            Some(b'+') | Some(b'-')  => Token::Sign,
            Some(b'e') | Some(b'E')  => Token::Exponent,
            Some(_) => Token::Unknown,
            None => Token::End,
        }
    }

}