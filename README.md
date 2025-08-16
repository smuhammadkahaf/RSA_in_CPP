# RSA_in_CPP

## Overview

**RSA_in_CPP** is a C++ console application that demonstrates the RSA cryptographic algorithm. It provides a user-friendly interface for generating RSA key pairs, encrypting and decrypting files, and managing cryptographic operations. The project is designed with modularity and clarity in mind, making it suitable for both educational and practical purposes.

## Features

- **RSA Key Generation:** Securely generate public and private RSA keys.
- **Encryption & Decryption:** Encrypt and decrypt text files using RSA.
- **File Management:** Read plaintext from files and write encrypted/decrypted output.
- **Interactive Console UI:** Menu-driven interface for ease of use.
- **Object-Oriented Design:** Clean separation of cryptographic logic and file handling.

## Project Structure

```
OOP__CEP/
├── crypto.h / crypto.cpp        # RSA cryptography logic (key generation, encryption, decryption)
├── file.h / file.cpp            # File input/output operations
├── crypto_ED.cpp                # Additional encryption/decryption logic
├── crypto_key.cpp               # Key management logic
├── function.cpp                 # Helper functions
├── main.cpp                     # Main program and user interface
├── OOP__CEP.vcxproj             # Visual Studio project file
├── OOP__CEP.vcxproj.filters     # Visual Studio project filters
```

## Getting Started

### Prerequisites
- Windows OS (uses `<windows.h>`)
- Visual Studio (recommended) or any C++17 compatible compiler

### Build Instructions
1. **Clone the repository:**
   ```
   git clone https://github.com/smuhammadkahaf/RSA_in_CPP.git
   ```
2. **Open the project:**
   - Open `OOP__CEP.sln` in Visual Studio.
3. **Build the solution:**
   - Press `Ctrl+Shift+B` or use the Build menu.

### Run Instructions
- Run the compiled executable from Visual Studio or the command line.
- Follow the on-screen menu to generate keys, encrypt, or decrypt files.

## Usage

1. **Generate Keys:**
   - Select the key generation option from the menu.
   - The program will display the public and private keys.

2. **Encrypt a File:**
   - Enter the filename to encrypt.
   - Provide the public key.
   - The encrypted content will be saved to a file.

3. **Decrypt a File:**
   - Enter the filename to decrypt.
   - Provide the private key.
   - The decrypted content will be saved to a file.

## File Descriptions

- **main.cpp:** User interface and program flow.
- **crypto.h / crypto.cpp:** RSA algorithm implementation.
- **file.h / file.cpp:** File operations. 
- **crypto_ED.cpp:** Additional encryption/decryption routines.
- **crypto_key.cpp:** Key management utilities.
- **function.cpp:** Helper functions.

## Security Notice

- **Keep your private key secure!** Never share it with anyone.
- The public key can be distributed freely.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Author

Developed by [smuhammadkahaf](https://github.com/smuhammadkahaf)
