<br />
    
<p align="center">
  <a href="https://github.com/cjoshi7/DS-Emacs">
    <img src="images/icon.png" alt="Logo" width="150" height="150">
  </a>

  <h1 align="center">Data Structure Editing Macros</h1>

  <p align="center">
    Edit abstract data structures through vim-inspired commands on the terminal
    <br />
    <a href="https://github.com/cjoshi7/DS-Emacs"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://youtu.be/r9-8qcNwKmk">View Demo</a>
    ·
    <a href="https://github.com/cjoshi7/DS-Emacs">Report Bug</a>
    ·
    <a href="https://github.com/cjoshi7/DS-Emacs">Request Feature</a>
  </p>
</p>

<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

<p align="center">
  <a href="https://github.com/cjoshi7/DS-Emacs">
    <img src="images/demo.png" alt="example-image" width=450 height=575>
  </a>
</p>

This is a C++ terminal application made to familiarize myself with abstract data structures and the concept of computational complexity. The purpose is to replicate the standard template library's hash table and create a trie from scratch.

### What it does
This application allows the user to manipulate massive data sets with vim-inspired macros.

### How I built it
This application is built using Dash with Python, the Plotly library to generate the choropleth map, and the Bootstrap framework to quickly develop the CSS. The New York Time's COVID-19 dataset was used along with a JSON map of the United States from Plotly.

### Challenges I ran into
It was difficult to actually find the data in a usable form online, because it was either fragmented or contained irrelevant data to my purpose. This introduced me to the pandas libraries to clean and filter the dataset. I've also never worked with visualizations of datasets before, so the hardest part was actually starting.

### Accomplishments that I'm proud of
I created my first deployable web API and made a visually appealing application to solve a real world problem, while introducing me to data science concepts along the way.

### What I learned
I learned the fundamentals of data science through cleaning and filtering data and how to make useful visualizations by taking advantage of python's many data science libraries. I also learned how to use a new web application framework with Dash.

## Getting Started

1. Clone the repo
   ```sh
   git clone https://github.com/cjoshi7/DS-Emacs
   ```
2. Run the precompiled binary
   ```sh
   ./DS-Emacs/data <txt file name>
   ```


<!-- USAGE EXAMPLES -->
## Usage

This tool can be used for research purposes to find the exact number of cases in a specific county on any day. It is useful to see the patterns of infection and death rate increases/decreases. For example, it can be seen that the number of infections skyrocketed in early January after the holiday season. The tool is useful for establishing patterns such as this.

_For more examples, please refer to the [Documentation](https://github.com/cjoshi7/meteorological-query-tool)_



<!-- ROADMAP -->
## Roadmap

__See the [open issues](https://github.com/cjoshi7/DS-Emacs) for a list of proposed features (and known issues).__
## TODO ##
* Manipulate the DOM using jQuery and AJAX calls. When the submit button is pressed, make a GET request to the server using the input fields.
    * PROBLEM: When the HTML form is submitted, the corresponding JS event listener doesnot reccognize the event, likely due to syntax error because of confusion between element vs id JS syntax. Figure out how to properly select DOM elements.
* Allow a range of dates to be selected on the HTML file and render coordinate plot using the database response. Use this instead of table.
* Change the padding and color of the Bootstrap classes in styles.css to center the input fields and make the background sky blue.
<br>
<p>
  The following features will be implemented in the indefinite future:
  <ol>
    <li>
      Expanded dataset to include:
      <ul>
        <li>Mask usage</li>
        <li>Population density</li>
        <li>Demographic breakdown</li>
      </ul>
    </li>
    <li>Dark theme through altered CSS</li>
    <li>An option to use the program in the command line</li>
  </ol>
</p>

<!-- CONTACT -->
## Contact

Chinar Joshi - chinarjoshi7@gmail.com

Project Link: [https://github.com/cjoshi7/covid19-date-selector](https://github.com/cjoshi7/covid19-date-selector)



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/othneildrew/Best-README-Template.svg?style=for-the-badge
[contributors-url]: https://github.com/othneildrew/Best-README-Template/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/othneildrew/Best-README-Template.svg?style=for-the-badge
[forks-url]: https://github.com/othneildrew/Best-README-Template/network/members
[stars-shield]: https://img.shields.io/github/stars/othneildrew/Best-README-Template.svg?style=for-the-badge
[stars-url]: https://github.com/othneildrew/Best-README-Template/stargazers
[issues-shield]: https://img.shields.io/github/issues/othneildrew/Best-README-Template.svg?style=for-the-badge
[issues-url]: https://github.com/othneildrew/Best-README-Template/issues
[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge
[license-url]: https://github.com/othneildrew/Best-README-Template/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/othneildrew
[product-screenshot]: images/screenshot.png
