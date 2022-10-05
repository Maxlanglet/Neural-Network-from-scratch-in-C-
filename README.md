Neural Networks in C++

TODO: Softmax have bugs, Conv layers




<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/Maxlanglet/Neural-Network-from-scratch-in-C-">
    <img src="images/nn.png" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">project_title</h3>

  <p align="center">
    project_description
    <br />
    <a href="https://github.com/Maxlanglet/Neural-Network-from-scratch-in-C-"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/Maxlanglet/Neural-Network-from-scratch-in-C-">View Demo</a>
    ·
    <a href="https://github.com/Maxlanglet/Neural-Network-from-scratch-in-C-/issues">Report Bug</a>
    ·
    <a href="https://github.com/Maxlanglet/Neural-Network-from-scratch-in-C-/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

<!-- [![Product Name Screen Shot][product-screenshot]](https://example.com) -->

This repository is my implementation of neural network from scratch in C++. It achieves up to 80% accuracy on the [MNIST Dataset](http://yann.lecun.com/exdb/mnist/), although it take some time to train the model on the full dataset on CPU for the complete dataset. Some optimization is still necessary. Furthermore, the Softmax activation function still needs implementation. It could also benefit from the advantages of convolutional layers.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



### Built With

* [![C++][C++.js]][C++-url]

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these simple example steps.

### Prerequisites

As prerequisites, you'll need an instalation of C++ 11 and cmake. To read images, you'll need to install open-cv for C++ ([opencv for c++](https://docs.opencv.org/4.x/d0/db2/tutorial_macos_install.html)). Furthermore, you can download the MNIST dataset and change the path to the folder in the `main.cpp` file. The easiest way I found was with [this repo](https://github.com/teavanist/MNIST-JPG).



### Installation

After installing open-cv, you can run the project:

1. Clone the repo
   ```sh
   git clone https://github.com/Maxlanglet/Neural-Networks-from-scratch-in-C-.git
   ```
2. Go into the repo
   ```sh
   cd path/to/folder
   ```
3. Run cmake (delete and modify files if necessary)
   ```sh
   cmake .
   ```
4. Run the program
   ```sh
   clear && make && ./main
   ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!--USAGE EXAMPLES
## Usage

Currently, the program doesn't save the models. Hence, the usage is not curreb-b--

_For more examples, please refer to the [Documentation](https://example.com)_

<p align="right">(<a href="#readme-top">back to top</a>)</p> -->



<!-- ROADMAP -->
## Roadmap

- [ ] Finish Softmax and correct bug
- [ ] Add conv layer
- [ ] Saving models
- [ ] Optimize more

See the [open issues](https://github.com/Maxlanglet/Neural-Network-from-scratch-in-C-/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

Contributions are more than welcome, feel free to add some features, correct and improve the code to your liking. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/your-branch`)
3. Commit your Changes (`git commit -m 'Add some Feature'`)
4. Push to the Branch (`git push origin feature/your-branch`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Maxime Langlet - maxime.langlet@outlook.be

Project Link: [Neural Networks from scratch in C++](https://github.com/Maxlanglet/Neural-Network-from-scratch-in-C-)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [Sebastien Lague](https://www.youtube.com/watch?v=hfMk-kjRv4c)
* [othneildrew](https://github.com/othneildrew/Best-README-Template)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[issues-shield]: https://img.shields.io/bitbucket/issues/MaxLanglet/Neural-Network-from-scratch-in-C-
[issues-url]: https://github.com/Maxlanglet/Neural-Network-from-scratch-in-C-/issues
[license-shield]: https://img.shields.io/badge/license-MIT-brightgreen
[license-url]: https://github.com/Maxlanglet/Neural-Network-from-scratch-in-C-/blob/main/LICENSE
[linkedin-shield]: https://img.shields.io/badge/LinkedIn-Link-yellowgreen
[linkedin-url]: https://www.linkedin.com/in/maxime-langlet-7a6a88b9/
<!-- [product-screenshot]: images/screenshot.png -->
[C++.js]: https://img.shields.io/badge/C%2B%2B-url-blue
[C++-url]: https://cplusplus.com