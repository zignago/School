hyps = [ '((not M) and C) <= (not H)' , '(not C) <= ((not M) or (not H))' ]

concl = 'M <= C'

fst = "{0:^3s}|{1:^3s}|{2:^3s}|{3:^8s}|{4:^7s}|{5:^3s}"
fst2 = "{0:^3d}|{1:^3d}|{2:^3d}|{3:^8d}|{4:^7d}|{5:^3d}"
div = "---+---+---+--------+-------+-------"

print(fst.format('M','C','H','~M&C->~H','~C->~M|~H','M->C'))

for M in range(2):
    for C in range(2):
        for H in range(2):
            print(div)
            print (fst2.format(M,C,H, eval(hyps[0]),
                eval(hyps[1]), eval(concl)))