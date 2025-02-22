# C++ Konzepte Übersicht

| Konzept |  |
|--|--|
| Move-Semantik | ein Mechanismus zur Optimierung der Speicherverwaltung |
| RAII | Resource Acquisition Is Initialization |
| Regelwerk | Die Regel des Drei, Fünf und Null in C++ |
| SFINAE | Substitution Failure Is Not An Error |
| Value Categories | In C++ gibt es verschiedene Wertekategorien, die beschreiben, wie ein Ausdruck verwendet werden kann |

---

<br>

## Move-Semantik in C++

> [!NOTE]
> Die Move-Semantik in C++ ist ein Mechanismus zur Optimierung der Speicherverwaltung und zur Vermeidung unnötiger Kopien. Sie wurde mit C++11 eingeführt und nutzt Ressourcenverschiebung (Resource Transfer) statt Kopieren.

Die Move-Semantik in C++ ermöglicht es, Ressourcen (z. B. Speicher oder Dateihandles) von einem Objekt auf ein anderes zu verschieben, anstatt sie zu kopieren. Dadurch werden unnötige Kopien vermieden, was die Leistung verbessert.

Dafür nutzt C++ Rvalue-Referenzen (&&). Wenn ein Objekt ein temporärer Wert (Rvalue) ist, kann es „günstig“ in ein anderes Objekt verschoben werden, ohne eine vollständige Kopie zu erzeugen. Das passiert zum Beispiel bei der Rückgabe von Objekten aus Funktionen oder bei std::move(), das ein Lvalue in ein Rvalue umwandelt.

Die Move-Semantik wird hauptsächlich in Move-Konstruktoren und Move-Zuweisungsoperatoren verwendet. Sie ist besonders nützlich für Klassen, die mit dynamischen Ressourcen arbeiten, wie std::vector, std::string oder std::unique_ptr.

---

<br>

## RAII - Resource Acquisition Is Initialization 

### Was ist RAII?

RAII ist ein zentrales Konzept in C++, das sicherstellt, dass Ressourcen (z. B. Speicher, Dateien, Locks) deterministisch verwaltet werden. Dabei wird eine Ressource in einem Objekt gekapselt, dessen Lebensdauer durch den Gültigkeitsbereich (Scope) bestimmt wird.
Warum RAII?

- Verhindert Ressourcenlecks (z. B. nicht freigegebener Speicher)
- Erhöht Sicherheit und Robustheit
- Reduziert die Komplexität von Code

> [!NOTE]
> Deterministisch bedeutet, dass das Verhalten eines Systems oder einer Funktion vorhersehbar und reproduzierbar ist. Wenn ein Prozess deterministisch ist, dann liefert er bei gleichen Eingaben immer das gleiche Ergebnis und verhält sich in jeder Ausführung identisch.

---

<br>

# Regelwerk - Die Regel des Drei, Fünf und Null in C++ 

Das Regelwerk für Ressourcenverwaltung in C++ hat sich mit der Weiterentwicklung der Sprache weiterentwickelt. Heute gibt es drei wichtige Regeln:

- Regel des Drei (Rule of Three) – C++98
- Regel des Fünf (Rule of Five) – C++11
- Regel des Null (Rule of Zero) – Moderne C++-Ansätze

Diese Regeln helfen, Ressourcen sicher zu verwalten und Memory Leaks oder doppelte Freigaben zu verhindern.

<br>

## 1. Regel des Drei (Rule of Three) – C++98

Die Regel des Drei besagt, dass, wenn eine Klasse einen eigenen Destruktor benötigt (weil sie eine Ressource verwaltet, z. B. Speicher, Datei-Handles, Netzwerkverbindungen), dann sollte sie auch einen eigenen Copy-Konstruktor und Copy-Assignment-Operator implementieren.
Drei notwendige Methoden:

- Destruktor – Gibt Ressourcen frei.
- Copy-Konstruktor – Erstellt eine tiefe Kopie.
- Copy-Assignment-Operator – Kopiert bestehende Objekte.

<br>

## 2. Regel des Fünf (Rule of Five) – C++11

Mit C++11 wurden Move-Semantik und r-Werte eingeführt. Dadurch kamen zwei weitere wichtige Methoden hinzu:
Fünf notwendige Methoden:

- Destruktor
- Copy-Konstruktor
- Copy-Assignment-Operator
- Move-Konstruktor – Übernimmt Ressourcen eines temporären Objekts.
- Move-Assignment-Operator – Übernimmt Ressourcen und gibt alte frei.

Wann ist Move-Semantik sinnvoll?

- Sie vermeidet teure Kopien.
- Sie erlaubt schnelles Ressourcenstehlen. 

<br>

## 3. Regel des Null (Rule of Zero) – Moderne C++

Die Regel des Null (Rule of Zero) sagt:

> [!NOTE]
> Schreibe überhaupt keine dieser fünf Methoden!
> Nutze stattdessen smarte Pointer (std::unique_ptr, std::shared_ptr) und andere Standardklassen.

Warum?

- Keine manuelle Speicherverwaltung notwendig.
- Verhindert Memory Leaks und Fehler.
- Nutzt RAII voll aus.

<br>

## Vergleich der Regeln: Wann welche anwenden?

|Regel	|Beschreibung	|Wann verwenden?|
|---|---|---|
|Regel des Drei	|Falls ein Destruktor benötigt wird, dann auch Copy-Konstruktor und Copy-Assignment implementieren.	|In C++98, wenn keine Move-Semantik verfügbar ist.|
|Regel des Fünf	|Falls eine Klasse ressourcenintensive Objekte verwaltet, sollten Move-Konstruktor und Move-Assignment ergänzt werden.	|In C++11 und neuer, wenn Move-Semantik sinnvoll ist.|
|Regel des Null	|Vermeide eigene Implementierungen, indem du RAII und Standardbibliotheken nutzt.|	Moderne C++-Entwicklung, wenn Standard-Ressourcenklassen genutzt werden können.|

---

<br>

## SFINAE - Substitution Failure Is Not An Error

SFINAE ist ein Konzept in C++, das dazu führt, dass fehlerhafte Substitutionen während der Template-Instanziierung nicht als Fehler gewertet werden, sondern dazu führen, dass eine andere Überladung oder Spezialisierung verwendet wird. Dies ist ein Kernmechanismus für Template-Metaprogrammierung.

### Wie funktioniert SFINAE?

Normalerweise, wenn man ein Template definiert, und ein Fehler in der Typeninstanziierung auftritt, erhältst man einen Kompilierfehler. Bei SFINAE wird diese Substitution jedoch nicht als Fehler betrachtet. Stattdessen wird der Compiler "weiter suchen", ob er eine andere passende Template-Überladung oder -Spezialisierung finden kann.

> [!NOTE]
> Substitution passiert, wenn der Compiler anstelle von T einen echten Typ (int, double, std::string, etc.) einsetzt und überprüft, ob der Code damit gültig bleibt.

--- 

<br>

# Value Categories

> [!Note]
> In C++ gibt es verschiedene Wertekategorien, die beschreiben, wie ein Ausdruck verwendet werden kann. Die wichtigsten sind Lvalues und Rvalues, aber es gibt noch feinere Unterteilungen.

<br>

## Lvalue (Left Value)

Ein Lvalue ist ein benannter Speicherbereich, der nach seiner Verwendung weiter existiert. Er kann auf der linken Seite einer Zuweisung stehen.

### 🔹 Beispiele für Lvalues:
```cpp
int x = 10;   // x ist ein Lvalue
x = 20;       // Lvalue kann verändert werden

std::string str = "Hallo"; // str ist ein Lvalue
str += " Welt";            // Kann verändert werden
```

<br>

## Rvalue (Right Value)

Ein Rvalue ist ein temporärer Wert, der keinen Namen hat und nur für den aktuellen Ausdruck existiert.

### 🔹 Beispiele für Rvalues:

```cpp
int y = 5 + 3; // 5 + 3 ergibt 8, das ist ein Rvalue
int z = 10;  
int w = z + 2; // (z + 2) ist ein Rvalue

std::string s = "Hallo" + std::string(" Welt"); // Das Ergebnis ist ein Rvalue
```

### 🚨 Wichtig: Rvalues können nicht auf der linken Seite einer Zuweisung stehen:
```cpp
(5 + 3) = 10; // ❌ Fehler: Ein Rvalue kann nicht verändert werden!
```

<br>

## Lvalue-Referenz (T&)

Lvalues können an Referenzen übergeben werden:

```cpp
int a = 10;
int& ref = a;  // OK: Lvalue-Referenz auf Lvalue
ref = 20;      // Ändert a
```

### Ein Rvalue kann nicht direkt an eine Lvalue-Referenz übergeben werden:
```cpp
int& r = 5; // ❌ Fehler: 5 ist ein Rvalue
```

<br>

## Rvalue-Referenz (T&&)

Mit Rvalue-Referenzen (T&&) kann man temporäre Objekte (Rvalues) fangen und weiterverwenden. Das ist die Grundlage der Move-Semantik.

```cpp
int&& r = 5;  // OK: Rvalue-Referenz auf ein Rvalue
```

### Das wird z. B. in Move-Konstruktoren genutzt:

```cpp
class MyClass {
public:
    MyClass(MyClass&& other) { 
        std::cout << "Move-Konstruktor\n"; 
    }
};
```

<br>

## Weitere Kategorien

### Zusätzlich gibt es noch:

- Prvalue (Pure Rvalue) → Ein reiner temporärer Wert, z. B. 42, x + y
- Xvalue (Expiring Value) → Ein Wert, der bald zerstört wird, z. B. std::move(obj)
- Glvalue (Generalized Lvalue) → Überbegriff für Lvalues und Xvalues

---

<br>






















