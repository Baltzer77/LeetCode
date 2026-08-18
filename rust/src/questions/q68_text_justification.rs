struct Solution {}

impl Solution {
    pub fn full_justify(words: Vec<String>, max_width: i32) -> Vec<String> {
        let n = words.len();
        let max_width = max_width as usize;
        let mut res: Vec<String> = Vec::new();
        
        let mut start = 0;
        loop {
            let mut size = 0;
            let mut end = start;
            while end <  n && words[end].len() + size <= max_width {
                size += words[end].len() + 1;
                end += 1;
            }
            size = size - 1;
            

            if end >= n {
                break;
            }

            // end should be exclusive
            let mut line = String::with_capacity(max_width);

            let word_count = end - start;

            // always add left most word
            let word = &words[start];
            line.push_str(word.as_str());

            // if only word add padding to right
            if word_count == 1 {
                let space_count = max_width - word.len();
                for _ in 0..space_count {
                    line.push(' ');
                }
            }
            else {
                let remaining_space = max_width - size;
                let space_between = 1 + remaining_space / (word_count - 1);
                let additional_spaces = remaining_space % (word_count - 1);

                for i in 0..word_count-1 {
                    let space_count = space_between + if i < additional_spaces {1} else {0};
                    for _ in 0..space_count {
                        line.push(' ');
                    }

                    let word  = &words[i + start + 1];
                    line.push_str(word.as_str());
                }
            }

            res.push(line);
            start = end;
        }

        // last line should be left-justified
        let mut last_line = String::with_capacity(max_width);
        
        for i in start..n {
            let word = &words[i];
            last_line.push_str(word.as_str());
            if i < n - 1 {
                last_line.push(' ');
            }
        }

        while last_line.len() < max_width {
            last_line.push(' ');
        }

        res.push(last_line);
        res
    }
}