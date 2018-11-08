Part 1: (5 points)

Let S = it is sunny, C = camping is fun, H = the homework is
done, and M = mathematics is easy.

  Translate into English: (M → H)∧(S →C)
    
    **A: If mathematics is easy then the homework is done and if it is sunny then camping is fun.**
    
   Translate into Propositional Logic: “Mathematics is easy or camping is fun, as long as it is sunny and the homework is done.”
        
    **A: (M v C) <-> (S ^ H)**
        
        
Part 2: (5 points)

Use a truth table to determine whether this is a tautology, contradiction, or neither: (¬B → ¬A) → ((¬B → A) → B)  

| A   | B | ¬A | ¬B | (¬B -> ¬A) | (¬B -> A) | (Q -> B) | (P -> R) |  
| ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |  
| T | T |  F |  F |	         T |         T |        T |       **T**|  
| T | F |  F |  T |	         F |         F |        F |       **T**|  
| F | T |  T |  F |	         T |         T |        T |       **T**|  
| F | F |  T |  T |	         T |	     T |        T |       **T**|  
  
   **Tautology.**
    
Use a truth table to determine whether this is a tautology, contradiction, or neither: ((A → B)∧(B → ¬A)) → A  
  
   |A| 	B| 	¬A| 	¬B| (A -> B)|  (B -> ¬A)| 	(Q ^ R)|    (S -> A)|
   | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |  
   |T| 	T| 	 F| 	 F| 	   T| 		   F|         F|       **T**|
   |T| 	F| 	 F| 	 T| 	   F| 		   T|         F|       **T**|
   |F| 	T| 	 T| 	 F|        T| 		   T|         T|       **F**|
   |F| 	F| 	 T| 	 T|        T| 		   T|         T|       **F**|
    
   **niether.**  
    
    
Part 3: (5 points)

For each of the following pairs of propositions, show that the
two propositions are logically equivalent by finding a chain of equivalences from one
to the other. State which definition or law of logic justifies each equivalence in the
chain.  

 (p ∧ q) → r , p → (q → r )
    
 1. (p ∧ q) → r = !(!p v !q) -> r      DeMorgans Law
 2.             = !(!(!p v !q) v r     Implication
 3.             = (!p v !q) v r        Double Negative
 4.             = !p v (!q v r)        Associative
 5.             = p -> (q -> r)        Implication **Done**

    
 (q ∨ r ) → p, (q → p)∧(r → p)
    
 1. (q ∨ r ) → p = !(q v r) v p            Implication
 2.              = (!q ^ !r) v p           Demorgans Law
 3.              = (!q v p) ^ (!r v p)     Distributive
 4.              = (q -> p) ^ (r -> p)     Implication **Done**
     

Part 4: (5 points)

Let Loves(x,y) mean “x loves y,” Traveler(x) mean “x is a traveler,”
City(x) mean “x is a city,” Lives(x,y) mean “x lives in y.”

 Translate into English: ∃x∀y∀z(City(x) ∧ Traveler (y)∧Lives(z,x)) → (Loves(y,x)∧ ¬Loves(z,x))  

    **There exists a city loved by all of the travelers but everyone that lives there does not love it.**  
   
 Translate into Predicate Logic: “No traveler loves the city they live in.”  
    
    **∃x∀y(Traveler(x) ^ City(y) ^ Lives(x,y)) -> ¬loves(x,y)**  
   
Extra Credit: (5 points)

Assuming: p → (q ∧ r ), s → r , r → p  
Prove: s → q. 
          
          1. p → (q ∧ r ) Given  
          2. s → r        Given  
          3. r → p        Given  
          4. s -> p       2,3 HS  
          5. p -> q       1 Simplification  
          6. s -> q       4,5 HS **Done**
         
          
          
Assuming: ¬(r ∨ s), ¬p → s, p → q. 
Prove: q  

          1. ¬(r ∨ s)     Given  
          2. ¬p → s       Given  
          3. p → q        Given  
          4. 
    

HINT:
Modus Ponen: If x -> q, and x, then q
Modus Tollens: If x -> q, and ~q, then ~x
