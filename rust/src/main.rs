
/* project use */
pub mod comp;
pub mod rev;

use comp::*;

pub fn main() {

    let comp_naif = comp::Naif::new();
    let comp_hash = comp::Hash::new();
    let comp_tab = comp::Tab::new();
    let comp_pol3 = comp::Pol3::new();
    
    println!("{}", rev::naif("ACTG".to_string(), &comp_naif));
    println!("{}", rev::naif("ACTG".to_string(), &comp_hash));
    println!("{}", rev::naif("ACTG".to_string(), &comp_tab));
    println!("{}", rev::naif("ACTG".to_string(), &comp_pol3));

    println!("{}", rev::allocate("ACTG".to_string(), &comp_naif));
    println!("{}", rev::allocate("ACTG".to_string(), &comp_hash));
    println!("{}", rev::allocate("ACTG".to_string(), &comp_tab));
    println!("{}", rev::allocate("ACTG".to_string(), &comp_pol3));

    println!("{}", rev::switch("ACTG".to_string(), &comp_naif));
    println!("{}", rev::switch("ACTG".to_string(), &comp_hash));
    println!("{}", rev::switch("ACTG".to_string(), &comp_tab));
    println!("{}", rev::switch("ACTG".to_string(), &comp_pol3));
}
