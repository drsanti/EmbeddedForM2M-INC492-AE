#[allow(unused_imports)]
use std::{thread, time::Duration};
use std::time::Instant;
use serial2::SerialPort;

#[allow(unused_imports)]
use std::io;

#[allow(unused_imports)]
use std::sync::{Arc, Mutex};


// Open COM port
fn open(com:&str) -> SerialPort {
	return SerialPort::open(com, 115200).unwrap();
}

fn main() {

	// Open COM5
    let port = open("COM5");

	// Create timer
	let timer = Instant::now();

	let mut cnt = 0;
	let mut oms = 0;
	let mut ticks = 0;
	loop {
		
		let ms = timer.elapsed().subsec_millis();	// MAX of ms is 1000.
		
		// Increase cnt by one every .5 seconds
		if oms != ms && ms % 500 == 0 {
			oms = ms;
			
			cnt = cnt + 1;
			if cnt >= 4 {
				cnt = 0;
				ticks += 1;
				println!("ticks: {}", ticks);
				port.write(b"led-inv\r\n").unwrap();
			}
		}

		// Do other stuffs
	}
}