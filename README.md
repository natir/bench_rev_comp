# Benchmark Reverse Complement

bench\_rev\_comp is a project to compare some reverse complement algorithme in some programing language.

## How to run the benchmark

1. Generate data

```
cd data
./generate_data -o data.csv
cd ..
```

2. Run benchmark

```
mkdir output
./run.py -i data/data.csv -o output/test -l ${list_of_language_you_want_bench}
```

3. Read the result, in output dir you find test_resume.csv with resume result, test test\_${language}\_raw.csv and test\_${language}\_${seq\_size}.png

## Project structure

* data: content script to generate data set file.
* cpp: source file to generate exectuable to run benchmark in C++

## Interface for each language

For each language we have one executable he respect this cli interface :

```
./${programing language}/bench ${nbcall} ${sequence}
```

and returns for each algorithme the time in microsecond in csv format, like this :

```
naive,tab,hash,pol3
200,3000,200,1
```

## Algorithm and implementation

In each language directory we found a algorithm.md file, he associate a short name to a description of algorithme and implementation specificity.

### Algorithm naming

Please don't use this charactere in your algorithm name '-'

## Contribution

You can create a new directory for your favorite language, add new algorithme in one language, translate some algorithme in another language, add another implementation of algorithme and make some modification in implementation (maybe your pull request generate big discussion).




