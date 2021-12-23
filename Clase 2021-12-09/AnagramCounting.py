import sys
m_tam=101
fact={0:1}

#RECURSIVO FACTORIAL
for i in range(1,m_tam):
    fact[i]=i*fact[i-1]

for main in sys.stdin:
    repite={}
    cad=str(main.split()[0])
    for carac in cad:
        if ord(carac) in repite:
            repite[ord(carac)]+=1
        else:
            repite[ord(carac)]=1
    rpta=fact[len(cad)]
    for i in repite:
        rpta//=fact[repite[i]]
    print(rpta)
