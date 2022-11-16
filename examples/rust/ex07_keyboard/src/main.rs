
use serial2::SerialPort;
use std::io;


// Open COM port
fn open(com:&str) -> SerialPort {
	return SerialPort::open(com, 115200).unwrap();
}

fn main() {

	// Open COM5
    let port = open("COM5");

    let mut line = String::new();

	println!("Input command: on | off | inv | x");
    while line != "x\r\n" {

        line.clear();

        io::stdin().read_line(&mut line).unwrap();

		if line == "on\r\n" {
			port.write(b"led-on\r\n").unwrap();
		}
		else if line == "off\r\n" {
			port.write(b"led-off\r\n").unwrap();	
		}
		else if line == "inv\r\n" {
			port.write(b"led-inv\r\n").unwrap();	
		}
    }

	println!("Bye!");
}