# Ejercicios propuestos – Semana 11 (Relaciones entre clases)

Ejercicios adicionales para los alumnos que terminen antes. Solo usan lo visto en la Semana 11: **asociación, agregación y composición**, con punteros, vectores de punteros y objetos por valor (sin herencia ni polimorfismo).

| # | Ejercicio | Tipo | Tiempo aprox. |
|---|-----------|------|---------------|
| 1 | Asociación en los dos sentidos | Extensión de A1 | 10–15 min |
| 2 | Un cliente con varios pedidos | Extensión de A1 | 15 min |
| 3 | Universidad → buscar y listar | Extensión de A2 | 15–20 min |
| 4 | Documento → índice y búsqueda | Extensión de A3 | 10–15 min |
| 5 | BattleBot → batalla por turnos | Extensión de A4 | 20 min |
| 6 | BattleBot → obstáculos y colisiones | Extensión de A4 | 15–20 min |
| 7 | Matrícula → varias secciones | Extensión de B1 | 20 min |
| 8 | Matrícula → reporte de la sección | Reto | 20–25 min |

---

## 1. Asociación en los dos sentidos

**Enunciado.** Con las clases `Cliente` y `Pedido` de A1, haga que el `Pedido` también conozca a su `Cliente`: agregue el atributo `Cliente* cliente` y el método `asignar_cliente(Cliente*)`. Modifique `asociar_pedido` del cliente para que, además de guardar el pedido, le avise al pedido quién es su cliente.

En el `main` imprima desde el pedido el nombre de su cliente. Luego cancele el pedido desde el cliente y responda: ¿el pedido sigue conociendo al cliente?

**Conceptos:** asociación bidireccional, referencias cruzadas entre dos clases, declaración adelantada (`class Cliente;`) para evitar que los dos `.h` se incluyan mutuamente.

**Diagrama de clase**

```mermaid
classDiagram
    class Cliente {
        -string nombre
        -Pedido* pedido
        +asociar_pedido(Pedido* pedido) void
        +cancelar_pedido() void
        +get_nombre() string
    }
    class Pedido {
        -string fecha
        -double monto
        -Cliente* cliente
        +asignar_cliente(Cliente* cliente) void
        +imprimir_con_cliente() void
    }
    Cliente --> Pedido : conoce
    Pedido --> Cliente : conoce
```

**Diagrama de flujo – programa principal**

```mermaid
flowchart TD
    A([Inicio]) --> B["pedido = new Pedido(...)"]
    B --> C["Cliente cliente('Ana')"]
    C --> D["cliente.asociar_pedido(pedido)"]
    D --> E["dentro de asociar_pedido:<br/>pedido->asignar_cliente(this)"]
    E --> F[/"pedido->imprimir_con_cliente()"/]
    F --> G["cliente.cancelar_pedido()"]
    G --> H[/"pedido->imprimir_con_cliente()<br/>¿sigue conociendo al cliente?"/]
    H --> I["delete pedido"]
    I --> J([Fin])
```

---

## 2. Un cliente con varios pedidos

**Enunciado.** Cambie el atributo `Pedido* pedido` de `Cliente` por `vector<Pedido*> pedidos`. Agregue:

- `agregar_pedido(Pedido*)`,
- `cancelar_pedido(string fecha)`: quita del vector el pedido de esa fecha (sin destruirlo),
- `monto_total()`: devuelve la suma de los montos de todos sus pedidos.

En el `main` cree tres pedidos, agrégueselos al cliente, muestre el total, cancele uno y vuelva a mostrar el total.

**Conceptos:** de un puntero simple a un vector de punteros, `erase` sobre un vector, recorrer punteros con `->`.

**Diagrama de clase**

```mermaid
classDiagram
    class Cliente {
        -string nombre
        -vector~Pedido*~ pedidos
        +agregar_pedido(Pedido* pedido) void
        +cancelar_pedido(string fecha) void
        +monto_total() double
        +imprimir() void
    }
    class Pedido {
        -string fecha
        -double monto
        +get_fecha() string
        +get_monto() double
        +imprimir() void
    }
    Cliente o-- Pedido : Agregación
```

**Diagrama de flujo – `monto_total()`**

```mermaid
flowchart TD
    A([Inicio]) --> B["total = 0<br/>i = 0"]
    B --> C{"i < pedidos.size()?"}
    C -- Sí --> D["total = total + pedidos[i]->get_monto()<br/>i = i + 1"]
    D --> C
    C -- No --> E[/"retornar total"/]
    E --> F([Fin])
```

---

## 3. Universidad → buscar y listar

**Enunciado.** Con las clases de A2, agregue a `Universidad`:

- `buscar_alumno(string codigo)`: devuelve el puntero al alumno o `nullptr`,
- `alumnos_del_curso(string codigo_curso)`: imprime los alumnos que llevan ese curso,
- `alumno_con_mas_cursos()`: devuelve el puntero al alumno matriculado en más cursos.

Para los dos últimos necesitará consultar los cursos de cada alumno: agregue a `Alumno` el método `lleva_curso(string codigo)` y `cantidad_cursos()`.

**Conceptos:** recorrer dos niveles de agregación (universidad → alumno → curso), búsqueda devolviendo punteros, comparar para hallar el máximo.

**Diagrama de clase**

```mermaid
classDiagram
    class Universidad {
        -string nombre
        -vector~Alumno*~ alumnos
        -vector~Curso*~ cursos
        +buscar_alumno(string codigo) Alumno*
        +alumnos_del_curso(string codigo_curso) void
        +alumno_con_mas_cursos() Alumno*
    }
    class Alumno {
        -string nombre
        -string codigo
        -vector~Curso*~ cursos
        +lleva_curso(string codigo) bool
        +cantidad_cursos() int
    }
    class Curso {
        -string nombre
        -string codigo
        +get_codigo() string
    }
    Universidad o-- Alumno : Agregación
    Universidad o-- Curso : Agregación
    Alumno o-- Curso : Agregación
```

**Diagrama de flujo – `alumnos_del_curso(codigo_curso)`**

```mermaid
flowchart TD
    A([Inicio]) --> B["i = 0"]
    B --> C{"i < alumnos.size()?"}
    C -- Sí --> D{"alumnos[i]->lleva_curso(codigo_curso)?"}
    D -- Sí --> E[/"imprimir alumnos[i]"/]
    D -- No --> F
    E --> F["i = i + 1"]
    F --> C
    C -- No --> G([Fin])
```

---

## 4. Documento → índice y búsqueda

**Enunciado.** Con las clases de A3, agregue a `Documento`:

- `imprimir_indice()`: muestra solo número y título de cada capítulo, en una línea por capítulo,
- `buscar_capitulo(int numero)`: devuelve el título del capítulo con ese número, o `"no existe"`,
- `renumerar()`: vuelve a numerar los capítulos de 1 a N según el orden del vector.

Pruebe agregando capítulos desordenados y llamando a `renumerar()`.

**Conceptos:** recorrer un vector de objetos **por valor** (se accede con `.`), modificar los elementos en su sitio, diferencia con el recorrido de punteros de los ejercicios anteriores.

**Diagrama de clase**

```mermaid
classDiagram
    class Documento {
        -string titulo
        -Capitulo capitulo
        -vector~Capitulo~ capitulos
        +imprimir_indice() void
        +buscar_capitulo(int numero) string
        +renumerar() void
    }
    class Capitulo {
        -int numero
        -string titulo
        +set_numero(int numero) void
        +get_numero() int
        +get_titulo() string
    }
    Documento *-- Capitulo : Composición
```

**Diagrama de flujo – `renumerar()`**

```mermaid
flowchart TD
    A([Inicio]) --> B["i = 0"]
    B --> C{"i < capitulos.size()?"}
    C -- Sí --> D["capitulos[i].set_numero(i + 1)<br/>i = i + 1"]
    D --> C
    C -- No --> E([Fin])
```

---

## 5. BattleBot → batalla por turnos

**Enunciado.** Con las clases de A4, agregue a `CBattleBox` el método `batalla()`: mientras queden al menos dos robots con vidas, en cada turno un robot golpea al siguiente de la lista. Cuando un robot llega a **0 vidas** se retira del tablero con `removerRobot()` y se avisa en pantalla. El método termina cuando queda un solo robot en pie y anuncia al ganador.

Imprima el tablero al inicio y al final de la batalla.

**Conceptos:** recorrer un vector de punteros modificándolo durante el recorrido, usar `golpear()` entre objetos de la misma clase, condición de fin de un bucle.

**Diagrama de clase**

```mermaid
classDiagram
    class CBattleBox {
        -vector~CRobot*~ m_Robots
        +batalla() void
        +removerRobot(TipoString pNombre) CRobot*
        +imprimirRobots() void
        +dibujarBattleBox() void
    }
    class CRobot {
        -TipoString m_Nombre
        -TipoEntero m_Vidas
        -TipoEntero m_Peso
        +golpear(CRobot &pEnemigo) void
        +getVidas() TipoEntero
        +getNombre() TipoString
    }
    CBattleBox o-- CRobot : Agregación
```

**Diagrama de flujo – `batalla()`**

```mermaid
flowchart TD
    A([Inicio]) --> B{"¿quedan 2 o más robots?"}
    B -- No --> H[/"anunciar ganador"/]
    B -- Sí --> C["atacante = m_Robots[i]<br/>objetivo = m_Robots[i + 1]"]
    C --> D["atacante->golpear(*objetivo)"]
    D --> E{"objetivo->getVidas() <= 0?"}
    E -- Sí --> F["removerRobot(objetivo->getNombre())<br/>avisar que se retira"]
    E -- No --> G
    F --> G["pasar al siguiente turno"]
    G --> B
    H --> I([Fin])
```

---

## 6. BattleBot → obstáculos y colisiones

**Enunciado.** Agregue a `CBattleBox` el método `moverRobot(string nombre, int x, int y)` que:

- busca el robot con `buscarRobot()`,
- valida que `(x, y)` esté dentro del tablero,
- si en esa casilla hay un obstáculo, llama a `Chocar()` y **no** mueve al robot,
- si está libre, llama a `moverse()`.

Agregue también `hayObstaculo(int x, int y)` que recorra el vector de obstáculos y devuelva `true` o `false`.

**Conceptos:** combinar las dos agregaciones del tablero, validar límites antes de modificar el estado, delegar en los métodos que ya existen.

**Diagrama de clase**

```mermaid
classDiagram
    class CBattleBox {
        -TipoEntero m_Altura
        -TipoEntero m_Ancho
        -vector~CRobot*~ m_Robots
        -vector~CObstaculo*~ m_Obstaculos
        +moverRobot(TipoString nombre, TipoEntero x, TipoEntero y) void
        +hayObstaculo(TipoEntero x, TipoEntero y) bool
        +buscarRobot(TipoString nombre) CRobot*
    }
    class CRobot {
        +moverse(TipoEntero pPosX, TipoEntero pPosY) void
        +Chocar(CObstaculo &pObstaculo) void
    }
    class CObstaculo {
        -TipoEntero m_Dureza
        +getPosX() TipoEntero
        +getPosY() TipoEntero
        +getDureza() TipoEntero
    }
    CBattleBox o-- CRobot : Agregación
    CBattleBox o-- CObstaculo : Agregación
```

**Diagrama de flujo – `moverRobot(nombre, x, y)`**

```mermaid
flowchart TD
    A([Inicio]) --> B["robot = buscarRobot(nombre)"]
    B --> C{"robot == nullptr?"}
    C -- Sí --> I[/"avisar que no existe"/]
    C -- No --> D{"(x, y) dentro del tablero?"}
    D -- No --> J[/"avisar fuera de rango"/]
    D -- Sí --> E{"hayObstaculo(x, y)?"}
    E -- Sí --> F["robot->Chocar(obstaculo)"]
    E -- No --> G["robot->moverse(x, y)"]
    F --> H([Fin])
    G --> H
    I --> H
    J --> H
```

---

## 7. Matrícula → varias secciones

**Enunciado.** Cree la clase `CHorario` que agrupe `m_Dia`, `m_HoraInicio` y `m_HoraFin`, y úsela **por composición** dentro de `CSeccion` (reemplazando los tres atributos sueltos). Luego cree una clase `CCiclo` que agregue varias secciones (`vector<CSeccion*>`) y ofrezca:

- `agregar_seccion(CSeccion*)`,
- `imprimir_secciones()`,
- `total_matriculados()`: la suma de los matriculados de todas sus secciones.

**Conceptos:** extraer atributos relacionados a una clase propia, composición dentro de una clase que ya tiene agregación, un nivel más de contenedores.

**Diagrama de clase**

```mermaid
classDiagram
    class CCiclo {
        -TipoString m_Nombre
        -vector~CSeccion*~ m_Secciones
        +agregar_seccion(CSeccion* pSeccion) void
        +imprimir_secciones() void
        +total_matriculados() TipoEntero
    }
    class CSeccion {
        -CCurso* m_Curso
        -CHorario m_Horario
        -vector~CAlumno*~ m_ListaAlumno
        +getNumeroMatriculados() TipoEntero
        +imprimir() void
    }
    class CHorario {
        -TipoEntero m_Dia
        -TipoEntero m_HoraInicio
        -TipoEntero m_HoraFin
        +CHorario(TipoEntero pDia, TipoEntero pHoraInicio, TipoEntero pHoraFin)
        +imprimir() void
    }
    CCiclo o-- CSeccion : Agregación
    CSeccion *-- CHorario : Composición
    CSeccion o-- CAlumno : Agregación
```

**Diagrama de flujo – `total_matriculados()`**

```mermaid
flowchart TD
    A([Inicio]) --> B["total = 0<br/>i = 0"]
    B --> C{"i < m_Secciones.size()?"}
    C -- Sí --> D["total = total + m_Secciones[i]->getNumeroMatriculados()<br/>i = i + 1"]
    D --> C
    C -- No --> E[/"retornar total"/]
    E --> F([Fin])
```

---

## 8. Matrícula → reporte de la sección (reto)

**Enunciado.** Agregue a `CSeccion` un reporte con:

- `vacantes_disponibles()`: `MAX_ALUMNOS` menos los matriculados,
- `promedio_creditos()`: promedio de créditos acumulados de los alumnos de la sección,
- `alumno_con_mas_creditos()`: devuelve el puntero al alumno con más créditos acumulados,
- `retirarAlumno(string codigo)`: saca al alumno del vector (sin destruirlo), devuelve su puntero y actualiza el contador,
- `cabe_en_laboratorio()`: `true` si el número de matriculados no supera la capacidad de computadoras del laboratorio.

Muestre el reporte completo, retire un alumno y vuelva a mostrarlo.

**Conceptos:** cálculos sobre un vector de punteros, división protegida contra el caso de lista vacía, mantener coherente el contador al modificar la lista, consultar un objeto compuesto (`m_Laboratorio`) desde el todo.

**Diagrama de clase**

```mermaid
classDiagram
    class CSeccion {
        -CLaboratorio* m_Laboratorio
        -vector~CAlumno*~ m_ListaAlumno
        -TipoEntero m_NumeroMatriculados
        +vacantes_disponibles() TipoEntero
        +promedio_creditos() double
        +alumno_con_mas_creditos() CAlumno*
        +retirarAlumno(TipoString codigo) CAlumno*
        +cabe_en_laboratorio() bool
    }
    class CAlumno {
        -TipoString m_Codigo
        -TipoEntero m_CreditosAcumulados
        +getCodigo() TipoString
        +getCreditosAcumulados() TipoEntero
    }
    class CLaboratorio {
        -TipoEntero m_NroComputadoras
        +getNroComputadoras() TipoEntero
    }
    CSeccion o-- CAlumno : Agregación
    CSeccion *-- CLaboratorio : Composición
```

**Diagrama de flujo – `promedio_creditos()`**

```mermaid
flowchart TD
    A([Inicio]) --> B{"lista vacía?"}
    B -- Sí --> C[/"retornar 0"/]
    B -- No --> D["suma = 0<br/>i = 0"]
    D --> E{"i < m_ListaAlumno.size()?"}
    E -- Sí --> F["suma = suma + m_ListaAlumno[i]->getCreditosAcumulados()<br/>i = i + 1"]
    F --> E
    E -- No --> G[/"retornar suma / cantidad"/]
    C --> H([Fin])
    G --> H
```
