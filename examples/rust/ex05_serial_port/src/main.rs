use serial2::SerialPort;
use std::io;


// Turn on led0
fn led0_on() -> Result<String, io::Error> {
	let port = SerialPort::open("COM5", 115200)?;
	port.write(b"led-on\r\n")?;
	Ok("led0-on ok".to_string())
}

// Turn off led0
fn led0_off() -> Result<String, io::Error> {
	let port = SerialPort::open("COM5", 115200)?;
	port.write(b"led-off\r\n")?;
	Ok("led0-off ok".to_string())
}

// Toggle led0
fn led0_inv() -> Result<String, io::Error> {
	let port = SerialPort::open("COM5", 115200)?;
	port.write(b"led-inv\r\n")?;
	Ok("led0-inv ok".to_string())
}

fn main() {
    println!("ex05 serial port!");
	let r = led0_on();
	// let r = led0_off();
	// let r = led0_inv();
	println!("Result: {:?}", r);
}
