test: env run_test
all: clean_tmp env run
zip: clean_tmp clean_env zip
commit: clean_tmp clean_env

env:
	sh make_scripts/set_env.sh

run:
	python3 project/main.py

clean_tmp:
	sh make_scripts/clean_tmp.sh

clean_env:
	sh make_scripts/clean_env.sh

zip:
	sh make_scripts/zip.sh

run_test:
	sh make_scripts/test.sh