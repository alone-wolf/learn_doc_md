# go goto

### eg:

    func main() {
        a := 10
        LOOP:
        for a<20{
            if a == 15{
                a += 1
                goto LOOP
            }
            println(a)
            a++
        }
    }

    run result: print 10 ~ 19

### eg:  error handler

    
    func main() {
	    for i:=0;i<10;i++{
		    for j:=0;j<10;j++{
			    if j == 2{
				    goto breakHere
			    }
		    }
	    }
	    return

        breakHere:
            println("done..")
    }

