% Title : jhbj
% namwookeim
% December 10, 2019

[TITLE]


* https://www.latex-project.org/get/
* https://pandoc.org/getting-started.html#step-1-install-pandoc
* https://miktex.org/download

pandoc test1.md -f markdown -t html -s -o test1.html

pandoc test1.md -s -o test1.pdf

# hjh { # intro }

~ Equation { #euler }
e = a+b
~


mkm

<a href="https://en.wikipedia.org/wiki/Hobbit#Lifestyle" title="Hobbit lifestyles">hobbit-hole</a>



[![An old rock in the desert](/assets/images/shiprock.jpg "Shiprock, New Mexico by Beau Rogers")](https://www.flickr.com/photos/beaurogers/31833779864/in/photolist-Qv3rFw-34mt9F-a9Cmfy-5Ha3Zi-9msKdv-o3hgjr-hWpUte-4WMsJ1-KUQ8N-deshUb-vssBD-6CQci6-8AFCiD-zsJWT-nNfsgB-dPDwZJ-bn9JGn-5HtSXY-6CUhAL-a4UTXB-ugPum-KUPSo-fBLNm-6CUmpy-4WMsc9-8a7D3T-83KJev-6CQ2bK-nNusHJ-a78rQH-nw3NvT-7aq2qf-8wwBso-3nNceh-ugSKP-4mh4kh-bbeeqH-a7biME-q3PtTf-brFpgb-cg38zw-bXMZc-nJPELD-f58Lmo-bXMYG-bz8AAi-bxNtNT-bXMYi-bXMY6-bXMYv)


Here's a simple footnote,[^1] and here's a longer one.[^bignote]

### My Great Heading {#custom-id}


<h3 id="custom-id">My Great Heading</h3>

[^bignote] : asfasffasfsafa


[Heading IDs](#heading-ids)

<a href="#heading-ids">Heading IDs</a>

First Term
: This is the definition of the first term.

Second Term
: This is one definition of the second term.
: This is another definition of the second term.


~~The world is flat.~~ We now know that the world is round.

- [x] Write the press release
- [x] Update the website
- [ ] Contact the media

asfjkasfjsakfjasklfjasklfklfjasljfasklfjasklfjaslkfjaslfjasf
asjfkasjfaaskfjaslkfjsaklfjaslfjasklfakslfjsjsajfkljfkalsjfqwoufiofjaslkfjasklfujqkfjkujaskfhasfjhaspofhaoifjasfasfjasfjasjfjas @mymynamwoo

sfksajfalskfjasf
asjf
asfjaskfjaslkfjaslkfjaslfjakslfjasljfalsjfasklfjasklfjalskjfaslkjfkasljfaklsfjakslfjaskljfaskljfalksfjaskfjakslfjaklsfjaklsjflaksfjaklsfjaklsfjlaksfjas [@mymynamwoo, p.35]

```diff
- This line got removed
+ This line got added
```

$-b \pm \sqrt{b^2 - 4ac} \over 2a$

.

##### The probability of getting (k) heads when flipping (n) coins
$\[P(E)   = {n \choose k} p^k (1-p)^{ n-k} \]$

##### The Lorenz Equations
$\dot{x} = \sigma(y-x) \\ \dot{y} = \rho x - y - xz \\ \dot{z} = -\beta z + xy$
$-b \pm \sqrt{b^2 - 4ac} \over 2a$

##### The Cauchy-Schwarz Inequality
$\[ \left( \sum_{k=1}^n a_k b_k \right)^2 \leq \left( \sum_{k=1}^n a_k^2 \right) \left( \sum_{k=1}^n b_k^2 \right) \]$

[Math examples are from here](http://www.mathjax.org/demos/tex-samples/)
