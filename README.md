# C++ Konzepte Übersicht

| Konzept |  |
|--|--|
| Allocator | |
| Auto-Storage Duration | |
| Bit Fields | |
| Compiler-Annotations | spezielle Attribute, die dem Compiler zusätzliche Hinweise geben, wie er den Code optimieren oder verarbeiten soll. |
| Constexpr | |
| Expression Templates | |
| Forward Declaration | |
| Inline-Funktionen | |
| Move-Semantik | ein Mechanismus zur Optimierung der Speicherverwaltung |
| Overloading und Overriding | |
| RAII | Resource Acquisition Is Initialization |
| Regelwerk | Die Regel des Drei, Fünf und Null in C++ |
| RTTI | RTTI (Run-Time Type Information) in C++ |
| RVO | Return Value Optimization |
| SFINAE | Substitution Failure Is Not An Error |
| Smart Pointers | |
| Template Metaprogramming | |
| Type Deduction | |
| Type Traits | |
| Value Categories | In C++ gibt es verschiedene Wertekategorien, die beschreiben, wie ein Ausdruck verwendet werden kann |
| Variadic Templates | |


---

<br>

# Allocator

> [!NOTE]
> Ein Mechanismus zur benutzerdefinierten Verwaltung von Speicher in C++-Containerklassen, der mehr Kontrolle über die Speicherzuweisung bietet.


---

<br>

# Auto-Storage Duration

> [!NOTE]
> Variablen, die eine "auto"-Speicherlebensdauer haben, wie z.B. lokale Variablen, die beim Eintritt in eine Funktion erzeugt und beim Verlassen zerstört werden.






---

<br>

# Bit Fields

> [!NOTE]
> Bitfelder ermöglichen es, strukturierte Daten auf niedrigster Ebene zu manipulieren, wobei der Platzbedarf von Variablen optimiert wird.




---

<br>

# Compiler-Annotations in C++

> [!NOTE]
> Compiler-Annotations in C++ sind spezielle Attribute, die dem Compiler zusätzliche Hinweise geben, wie er den Code optimieren oder verarbeiten soll. Diese Anmerkungen haben keinen Einfluss auf das Verhalten des Programms zur Laufzeit, können jedoch die Effizienz und Lesbarkeit des Codes erhöhen, indem sie dem Compiler bei der Entscheidung helfen, wie er den Code verarbeitet.

Zu den häufigsten Compiler-Annotations gehören:

- `[[nodiscard]]`: Markiert den Rückgabewert einer Funktion als wichtig, sodass der Compiler eine Warnung ausgibt, wenn der Rückgabewert ignoriert wird. Dies hilft, Fehler zu vermeiden, bei denen wichtige Informationen verloren gehen.

- `[[likely]]` und `[[unlikely]]`: Diese Attribute geben dem Compiler Hinweise zur Wahrscheinlichkeit, dass ein bestimmter Codepfad ausgeführt wird. [[likely]] signalisiert, dass der Pfad wahrscheinlich ausgeführt wird, während [[unlikely]] darauf hinweist, dass der Pfad weniger wahrscheinlich ist. Diese Informationen können verwendet werden, um die Branch-Vorhersage zu optimieren und die Leistung zu verbessern.

- `[[maybe_unused]]`: Zeigt an, dass eine Variable, Funktion oder ein anderes Symbol möglicherweise nicht verwendet wird. Der Compiler kann dann Warnungen vermeiden, die ansonsten beim Vorhandensein ungenutzter Code-Teile ausgelöst würden.

- `[[nodiscard]]`: Ein weiteres nützliches Attribut, das für den Rückgabewert von Funktionen verwendet wird, wenn dieser unbedingt beachtet werden muss. Das ist insbesondere bei Funktionen wichtig, die kritische Informationen liefern.

- `[[deprecated]]`: Wird verwendet, um zu kennzeichnen, dass eine Funktion oder ein Feature in einer zukünftigen Version von C++ nicht mehr unterstützt wird. Der Compiler gibt eine Warnung aus, wenn diese veralteten Funktionen verwendet werden, um Entwickler auf die Notwendigkeit der Migration hinzuweisen.

- `[[fallthrough]]`: Ein Hinweis, dass in einem switch-Statement das Fall-Label absichtlich "durchfällt". Normalerweise gibt der Compiler eine Warnung, wenn ein Fall ohne ein break-Statement durchfällt, aber mit [[fallthrough]] kann dies explizit erlaubt werden.

- `[[nodiscard]]`: Ein weiteres Attribut, das darauf hinweist, dass eine Rückgabe einer Funktion nicht ignoriert werden sollte, da der Rückgabewert eine Bedeutung hat.

- `[[carries_dependency]]`: Wird in multithreaded Anwendungen verwendet, um dem Compiler mitzuteilen, dass eine Variable eine Abhängigkeit aufweist, die über mehrere Threads hinweg beachtet werden muss.

Diese Anmerkungen helfen dem Compiler, den Code effizienter zu optimieren und Fehler zu vermeiden, indem sie explizit auf wichtige Aspekte des Codes hinweisen. Sie bieten Entwicklern eine einfache Möglichkeit, das Verhalten des Compilers zu steuern und die Codequalität zu verbessern.




---

<br>

# Constexpr

> [!NOTE]
> Ein Mechanismus, der es ermöglicht, dass Funktionen zur Compile-Zeit ausgewertet werden, was zu einer höheren Leistung führen kann.



---

<br>

# Expression Templates

> [!NOTE]
> Ein fortgeschrittenes Konzept, das es ermöglicht, mathematische Ausdrücke während der Kompilierung zu optimieren und die Auswertungsreihenfolge festzulegen.





---

<br>

# Forward Declaration

> [!NOTE]
> Ein Konzept, das es ermöglicht, auf ein noch nicht definiertes Element zu verweisen (z.B. bei Zeigern auf noch nicht deklarierte Typen).




---

<br>

# Inline-Funktionen

> [!NOTE]
> Inline-Funktionen werden vom Compiler direkt an der Stelle eingefügt, an der sie aufgerufen werden, um Overhead zu vermeiden.





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

# Overloading und Overriding

> [!NOTE]
> Das Überladen von Funktionen und das Überschreiben von virtuellen Funktionen in abgeleiteten Klassen sind grundlegende Mechanismen der Polymorphie in C++.










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

## RTTI (Run-Time Type Information) in C++

> [!NOTE]
> RTTI steht für Run-Time Type Information und ist ein Mechanismus in C++, der es ermöglicht, zur Laufzeit Informationen über den Typ eines Objekts zu erhalten. Dies ist besonders hilfreich, wenn man mit Vererbung und Polymorphismus arbeitet.

<br>

## Was ist RTTI?

RTTI ermöglicht es, zur Laufzeit den tatsächlichen Typ eines Objekts zu ermitteln, auch wenn man nur einen Zeiger oder eine Referenz auf eine Basisklasse hat. Dadurch lässt sich die richtige Methode oder das richtige Verhalten für das Objekt auswählen, basierend auf seinem tatsächlichen (dynamischen) Typ und nicht nur auf dem statischen Typ des Zeigers oder der Referenz.

<br>

## Wie funktioniert RTTI?

> [!NOTE]
> RTTI ist in C++ besonders nützlich in Verbindung mit Polymorphismus. Die zentrale Funktion von RTTI ist die Verwendung von typeid und dynamic_cast.

<br>

### typeid
Mit typeid kann der tatsächliche Typ eines Objekts zur Laufzeit ermittelt werden. Der Ausdruck typeid(obj) gibt ein type_info-Objekt zurück, das Informationen über den Typ von obj enthält.

<br>

### dynamic_cast
dynamic_cast wird verwendet, um sicherzustellen, dass eine Run-Time-Typprüfung durchgeführt wird, wenn ein Zeiger oder eine Referenz von einer Basisklasse auf eine abgeleitete Klasse konvertiert wird. Es wird eine sichere Umwandlung durchgeführt, die im Falle eines Fehlers (d.h., wenn der Umwandlungstyp nicht korrekt ist) nullptr zurückgibt.


---

<br>

## Return Value Optimization (RVO) in C++

> [!NOTE]
> Return Value Optimization (RVO) ist eine Compiler-Optimierung in C++, die das unnötige Kopieren von Rückgabewerten aus Funktionen vermeidet. Dadurch wird die Performance verbessert, indem ein temporäres Objekt direkt im Speicher des Zielobjekts erstellt wird, anstatt es erst zu kopieren.








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

# Smart Pointers

> [!NOTE]
> Diese sind Teil der modernen C++-Speicherverwaltung und beinhalten `std::unique_ptr`, `std::shared_ptr` und `std::weak_ptr`, die den Umgang mit Speicherressourcen sicherer und effizienter machen.




---

<br>

# Template Metaprogramming

> [!NOTE]
> Ein fortgeschrittener Mechanismus, der Templates zur Compile-Zeit verwendet, um Code zu generieren oder zu optimieren.



---

<br>

# Typenabgleich (Type Deduction)

> [!NOTE]
> In C++11+ wird der Typ von Variablen oft automatisch abgeleitet (z.B. durch auto), was den Code kompakter und weniger fehleranfällig macht.




---

<br>

# Type Traits

> [!NOTE]
> Ein Mechanismus, der es ermöglicht, zur Compile-Zeit Informationen über den Typ zu erhalten (z.B. `std::is_integral`, `std::is_pointer`).







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






---

<br>

# Variadic Templates

> [!NOTE]
> Mit Variadic Templates können Funktionen und Klassen mit einer beliebigen Anzahl von Parametern definiert werden, was besonders in Template-Metaprogrammierung und bei der Implementierung von Wrappern nützlich ist.

























































