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

### Was ist RAII?

RAII ist ein zentrales Konzept in C++, das sicherstellt, dass Ressourcen (z. B. Speicher, Dateien, Locks) deterministisch verwaltet werden. Dabei wird eine Ressource in einem Objekt gekapselt, dessen Lebensdauer durch den Gültigkeitsbereich (Scope) bestimmt wird.
Warum RAII?

- Verhindert Ressourcenlecks (z. B. nicht freigegebener Speicher)
- Erhöht Sicherheit und Robustheit
- Reduziert die Komplexität von Code

> [!NOTE]
> Deterministisch bedeutet, dass das Verhalten eines Systems oder einer Funktion vorhersehbar und reproduzierbar ist. Wenn ein Prozess deterministisch ist, dann liefert er bei gleichen Eingaben immer das gleiche Ergebnis und verhält sich in jeder Ausführung identisch.
