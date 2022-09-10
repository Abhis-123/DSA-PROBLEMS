
def find_permutations(string):
        res = set()
        string = list(string)
        n = len(string)
        if string.__len__()<= 1:
            res.append("".join(string))
            return res
            
        def permute(a, l, r): 
            if l==r: 
                res.add("".join(a))
            else: 
                for i in range(l,r): 
                    a[l], a[i] = a[i], a[l] 
                    permute(a, l+1, r) 
                    a[l], a[i] = a[i], a[l]
        permute(string, 0, n)
        res = list(res)
        res.sort()
        return res
        
if __name__ == "__main__":
    print(find_permutations("ABC"))