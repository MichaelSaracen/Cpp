# C++ Konzepte Übersicht

| Konzept |  |
|--|--|
| SFINAE | Substitution Failure Is Not An Error |

---

## SFINAE - Substitution Failure Is Not An Error

SFINAE ist ein Konzept in C++, das dazu führt, dass fehlerhafte Substitutionen während der Template-Instanziierung nicht als Fehler gewertet werden, sondern dazu führen, dass eine andere Überladung oder Spezialisierung verwendet wird. Dies ist ein Kernmechanismus für Template-Metaprogrammierung.

### Wie funktioniert SFINAE?

Normalerweise, wenn man ein Template definiert, und ein Fehler in der Typeninstanziierung auftritt, erhältst man einen Kompilierfehler. Bei SFINAE wird diese Substitution jedoch nicht als Fehler betrachtet. Stattdessen wird der Compiler "weiter suchen", ob er eine andere passende Template-Überladung oder -Spezialisierung finden kann.

> [!NOTE]
> Substitution passiert, wenn der Compiler anstelle von T einen echten Typ (int, double, std::string, etc.) einsetzt und überprüft, ob der Code damit gültig bleibt.


--- 

## RAII - Resource Acquisition Is Initialization 
