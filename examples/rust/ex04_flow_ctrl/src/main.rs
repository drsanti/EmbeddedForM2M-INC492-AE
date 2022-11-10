fn main() {

	let x = 56;

	if x % 2 == 0  {
		println!("Hello");
	}
	else {
		println!("World");
	}

	let c = false;
	let n = if c { 5 } else { 6 };
	println!("n: {n}");


	let mut counter = 0;

    let result = loop {
        counter += 1;

        if counter == 10 {
            break counter * 2;
        }
    };

    println!("The result is {result}");
}
