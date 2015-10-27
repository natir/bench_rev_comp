
/* standard use */
use std::collections::HashMap;

pub trait Base {
    fn new() -> Self;
    
    fn nuc2nuc(&self, nuc: char) -> char;
}

pub struct Naif;

impl Base for Naif {

    fn new() -> Naif {
        return Naif;
    }
    
    fn nuc2nuc(&self, nuc: char) -> char {
        if nuc == 'A' {
            return 'T';
        } else if nuc == 'C' {
            return 'G';
        } else if nuc == 'T' {
            return 'A';
        } else {
            return 'C';
        }
    }
}

pub struct Hash {
    hash_nuc: HashMap<char, char>,
}

impl Base for Hash {

    fn new() -> Hash {
        let mut hash = HashMap::new();
        hash.insert('A', 'T');
        hash.insert('T', 'A');
        hash.insert('C', 'G');
        hash.insert('G', 'C');
        
        return Hash { hash_nuc : hash };
    }
    
    fn nuc2nuc(&self, nuc: char) -> char {
        return self.hash_nuc[&nuc];
    }
}

pub struct Tab {
    tab_nuc: [char; (('T' as u8) + 1) as usize]
}

impl Base for Tab {

    fn new() -> Tab {
        let mut tab: [char; (('T' as u8) + 1) as usize] = ['A'; (('T' as u8) + 1) as usize];
        tab['A' as u8 as usize] = 'T';
        tab['T' as u8 as usize] = 'A';
        tab['C' as u8 as usize] = 'G';
        tab['G' as u8 as usize] = 'C';

        return Tab { tab_nuc : tab };
    }

    fn nuc2nuc(&self, nuc: char) -> char {
        return self.tab_nuc[nuc as u8 as usize]
    }
}

pub struct Pol3;

impl Base for Pol3 {

    fn new() -> Pol3 {
        return Pol3;
    }

    fn nuc2nuc(&self, nuc: char) -> char {
        return self.__nuc2nuc(nuc as u8) as char;
    }
}

impl Pol3 {
    fn __nuc2nuc(&self, nuc: u8) -> u8 {
        return ((((-0.045625 as f32 * nuc as f32 + 10.1787 as f32) * nuc as f32) - 753.8 as f32) * nuc as f32 + 18606 as f32) as u8; 
    }
}
