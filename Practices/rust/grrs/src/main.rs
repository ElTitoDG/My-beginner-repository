#![allow(unused)]

use clap::Parser;

//Search for a pattern in a file and diplay the lines that contain it
#[derive(Parser)]
struct Cli {
    //The pattern to look for
    pattern: String,
    //The path to the file to read
    path: std::path::PathBuf,
}

fn main() {

    let pb = indicatif::ProgressBar::new(100);
    for i in 0..100 {
        let args = Cli::parse();

        let content = std::fs::read_to_string(&args.path).expect("could not read file");
        for line in content.lines() {
            if line.contains(&args.pattern) {
                println!("{}", line);
            }
        }
        pb.println(format!("[+] finished #{}", i));
        pb.inc(1);
    }
    pb.finish_with_message("Done");

}
