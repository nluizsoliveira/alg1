all: env run clean

env:
	python3 -m venv env
	. env/bin/activate
	pip install -e .

run:
	python3 project/main.py

clean:
	rm -rf env
	rm -rf project.egg-info
	rm -f trab.zip

zip:
	zip -r trab.zip *.py Makefile