Entanglement 0.1.0.0
=====================

Intro
---------------------
The Entanglement(ETG) blockchain exists in the Duality binary architecture as an asset and in turn for [Entanglement(ETG)](https://github.com/entanglement-io/entanglement) is its real world interface.

Entanglement is a digital currency that enables instant payments to anyone, anywhere in the world. Entanglement uses peer-to-peer technology to operate with no central authority (decentralization): managing transactions and issuing currency (ETG) are carried out collectively by the Entanglement network. Entanglement is the name of open source software which enables the use of the currency ETG.

Setup
---------------------
[Entanglement](http://github.com/entanglement-io/entanglement) is the original Entanglement client and it builds the backbone of the network. However, it downloads and stores the entire history of Entanglement transactions (which is currently several GBs); depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more. Thankfully you only have to do this once. If you would like the process to go faster you can [download the blockchain directly](bootstrap.md).

Running
---------------------
The following are some helpful notes on how to run Entanglement on your native platform.

### Unix

You need the Qt4 run-time libraries to run Entanglement-Qt. On Debian or Ubuntu:

	sudo apt-get install libqtgui4

Unpack the files into a directory and run:

- bin/32/entanglement-qt (GUI, 32-bit) or bin/32/entanglementd (headless, 32-bit)
- bin/64/entanglement-qt (GUI, 64-bit) or bin/64/entanglementd (headless, 64-bit)



### Windows

Unpack the files into a directory, and then run entanglement-qt.exe.

### OSX

Drag Entanglement-Qt to your applications folder, and then run Entanglement-Qt.

### Need Help?

* Ask for help on the [BitcoinTalk](https://bitcointalk.org/) forums.

Building
---------------------
The following are developer notes on how to build Entanglement on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [OSX Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)

Development
---------------------
The Entanglement repo's [root README](https://github.com/entanglement-io/entanglement/blob/master/README.md) contains relevant information on the development process and automated testing.

- [Coding Guidelines](coding.md)
- [Multiwallet Qt Development](multiwallet-qt.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Source Code Documentation (External Link)](https://dev.visucore.com/entanglement/doxygen/) ***TODO***
- [Translation Process](translation_process.md)
- [Unit Tests](unit-tests.md)

### Resources
* Discuss on the [BitcoinTalk](https://bitcointalk.org/) forums, in the Development & Technical Discussion board.

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Tor Support](tor.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)

License
---------------------
Distributed under the [MIT/X11 software license](http://www.opensource.org/licenses/mit-license.php).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](https://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
