src := src

.PHONY: biblioteca analise

biblioteca:
	$(MAKE) --directory=$(src)
	mv src/biblioteca biblioteca

analise:
	python analise/gerar_testes.py

clean:
	$(MAKE) clean --directory=$(src)
	rm biblioteca tests.sh
