hyps = [ '(q and r) <= p','r or (not q)', 'q <= p' ]

concl = '(p and q) <= r'

fst = "{0:^3s}|{1:^3s}|{2:^3s}|{3:^8s}|{4:^7s}|{5:^9s}|{6:^3s}"
fst2 = "{0:^3d}|{1:^3d}|{2:^3d}|{3:^8d}|{4:^7d}|{5:^9d}|{6:^3d}"
div = "---+---+---+--------+-------+---------+-------"

print(fst.format('p','q','r','p&r->q','r|~q','q->p','p&q->r'))

for p in range(2):
    for q in range(2):
        for r in range(2):
            print(div)
            print (fst2.format(p,q,r, eval(hyps[0]),
                eval(hyps[1]), eval(hyps[2]), eval(concl)))