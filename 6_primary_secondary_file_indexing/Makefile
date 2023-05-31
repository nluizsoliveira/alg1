test: clean_env env prepare_tests process_inputs assert_outputs
all: env run clean_env

env:
	python3 -m venv env
	. env/bin/activate
	pip install -e .

run:
	python3 project/main.py

clean_env:
	rm -rf env
	rm -rf project.egg-info
	rm -f trab.zip
	rm -rf project/output_files

prepare_tests:
	cd project/tests/integration_test/; \
	python3 0_prepare_tests.py

process_inputs:
	cd project/tests/integration_test/; \
	python3 1_process_inputs.py > dumped_stdout/stdout

assert_outputs:
	cd project/tests/integration_test/; \
	python3 2_assert_outputs.py
	
zip:
	zip -r trab.zip *.py Makefile