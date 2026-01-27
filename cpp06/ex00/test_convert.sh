#!/bin/zsh
# Script para probar el convertidor de tipos

EXEC=./ScaleConverter

echo "\n--------Pruebas de char:--------"
echo "\nPrueba 'a':"
$EXEC a
echo "\nPrueba 'Z':"
$EXEC Z
echo "\nPrueba '!':"
$EXEC '!'

echo "\n\n--------Pruebas de int:--------"
echo "\nPrueba 0:"
$EXEC 0
echo "\nPrueba 42:"
$EXEC 42
echo "\nPrueba -123:"
$EXEC -123
echo "\nPrueba +7:"
$EXEC +7

echo "\n\n--------Pruebas de float:--------"
echo "\nPrueba 4.2f:"
$EXEC 4.2f
echo "\nPrueba -3.14f:"
$EXEC -3.14f
echo "\nPrueba +0.0f:"
$EXEC +0.0f
echo "\nPrueba nanf:"
$EXEC nanf
echo "\nPrueba +inff:"
$EXEC +inff

echo "\n\n--------Pruebas de double:--------"
echo "\nPrueba 4.2:"
$EXEC 4.2
echo "\nPrueba -3.14:"
$EXEC -3.14
echo "\nPrueba +0.0:"
$EXEC +0.0
echo "\nPrueba nan:"
$EXEC nan
echo "\nPrueba +inf:"
$EXEC +inf
echo "\nPrueba -inf:"
$EXEC -inf

echo "\n\n--------Pruebas desconocidas:--------"
echo "\nPrueba abc:"
$EXEC abc
echo "\nPrueba 12a:"
$EXEC 12a
echo "\nPrueba --:"
$EXEC --
echo "\nPrueba ++:"
$EXEC ++
