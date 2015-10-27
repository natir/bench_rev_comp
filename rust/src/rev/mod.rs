
/* standard use */
use std::string::String;

use super::comp;

pub fn naif<C: comp::Base>(seq: String, comp: &C) -> String {

    let mut rev_comp = String::new();

    for nuc in seq.chars().rev() {
        rev_comp.push(comp.nuc2nuc(nuc));
    }

    return rev_comp;
}

pub fn allocate<C: comp::Base>(seq: String, comp: &C) -> String {

    let mut rev_comp = String::with_capacity(seq.len());

    for ord in seq.chars().rev() {
        rev_comp.push(comp.nuc2nuc(ord));
    }

    return rev_comp;
}

pub fn switch<C: comp::Base>(mut seq: String, comp: &C) -> String {
    let mut tmp: char;

    unsafe {
        let mut begin = 0;
        let mut end = seq.len() - 1;
   
        while begin <= end {
            tmp = comp.nuc2nuc(seq.as_mut_vec()[begin] as char);
            seq.as_mut_vec()[begin] = comp.nuc2nuc(seq.as_mut_vec()[end] as char) as u8;
            seq.as_mut_vec()[end] = tmp as u8;

            begin += 1;
            end -= 1;
        }
    }

    return seq;
}
