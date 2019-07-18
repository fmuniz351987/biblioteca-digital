import itertools

tipos_qs = ('QNR', 'QC', 'QM3', 'QI1', 'QI5', 'QI10', 'QPE')
ordenacao_vetor = ('Ale', 'OrdC', 'OrdD')
tamanho_vetor = tuple(range(50_000, 500_001, 50_000))

with open('tests.sh', 'w+') as file:
    file.write('ulimit -s 204800\n')
    file.write('echo "tipo_sort ord_vetor tamanho_vetor n_comp n_mov tempo" >> analise/results.log\n')
    for qs, ord_v, N in itertools.product(tipos_qs, ordenacao_vetor, tamanho_vetor):
        file.write(f'./biblioteca {qs} {ord_v} {N} >> analise/results.log\n')
