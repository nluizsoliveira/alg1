all: env run exit

env:
	python3 -m venv env
	. env/bin/activate
	pip install -e .

run:
	python3 project/main.py

exit:
	rm -rf env
	rm -rf project.egg-info

zip:
	zip -r trab.zip *.py Makefile