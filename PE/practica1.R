# --  C R E A C I Ó N   D E   L A S   V A R I A B L E S  --

# Semilla para reproducibilidad
#set.seed(420)

# Número de días
dias = 10

# Generar datos de visitantes (entre 50 y 200 personas por día)
visitantes <- sample(50:200, dias, replace = TRUE)

#Generar el gasto medio de cada visitante en cada día
gasto_por_visitante <- runif(dias, min = 30, max = 100) 

# Generar datos de ingresos multiplicando el gasto medio por el número de visitantes
ingresos <- visitantes * gasto_por_visitante

# Redondear los ingresos a dos decimales
ingresos = round(ingresos, 2)

# Crear un data frame con los datos
datos_tienda <- data.frame(Visitantes = visitantes, Ingresos = ingresos)

# Mostrar los datos
print(datos_tienda)

# - - -


# --  I N G R E S O S   T O T A L E S  --

total = sum(ingresos)
print(paste('Ingresos totales:', total, '€'))

# - - -


# --  C O E F I C I E N T E   D E   C O R R E L A C I Ó N  --

# Cálculo de correlación entre visitantes e ingresos
correlacion = cor(visitantes, ingresos, method = c("pearson"))
print(paste('Coeficiente de correlación (Pearson):',correlacion))
# La correlación entre ingresos y visitantes oscila en los positivos debido a el uso del
# número de clientes en el cálculo de de los ingresos, de manera que:
#   1. Se crea aleatoriamente una media de gasto por visitante en un día
#   2. Se multiplica esa media por el número de visitantes para hallar el ingreso diario
# A pesar de ello, si la media aleatoria es muy baja un día con muchos visitantes y alta
# otro día con pocos visitantes reducirá el coeficiente, pero nunca llegando a negativo.

# - - -


# -- R E C T A   D E   R E G R E S I Ó N - - 

# Creación de la recta
linea_reg <- lm(ingresos ~ visitantes)
#summary(linea_reg)
# Dibujado de la gráfica. Los puntos indicarán el número de ingresos y el de visitantes. pch es el icono de estos puntos
plot(visitantes, ingresos, main = 'Recta de regresión', xlab = 'Visitantes', ylab = 'Ingresos', pch = 20)
# Dibujado de la recta de regresión sobre la gráfica
abline(linea_reg, col = 'blue')

# - - -

#
#
#
#FINAL OUTPUT
cat('Ingresos totales:', total, '€\n', 'Coeficiente de correlación (Pearson):',correlacion)
summary(linea_reg)


