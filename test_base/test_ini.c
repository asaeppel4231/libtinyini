#include <criterion/criterion.h>
#include <stdio.h>
#include <stdlib.h>
#include "ini.h"

// Test 1: Fehlende eckige Klammer zu (invalid_section_end_missing.ini)
Test(INI_Härtetest, Fehlendes_Sektions_Ende) {
    ini_t *config = ini_load("test_data/invalid_section_end_missing.ini");
    cr_assert_not_null(config, "Parser ist bei fehlendem ']' abgestürzt!");
    
    // Da die Sektion nie geschlossen wurde, darf kein valider Key existieren
    cr_assert_null(ini_get(config, "abc", "abc"), "Ungültige Sektion sollte keine Keys liefern!");
    ini_free(config);
}

// Test 2: Sektions-Chaos mit direkt folgendem Key
Test(INI_Härtetest, Sektion_Abbruch_Mit_Key) {
    ini_t *config = ini_load("test_data/invalid_section_end_missing_with_one_key.ini");
    cr_assert_not_null(config, "Parser ist bei Abbruch mit Key abgestürzt!");
    ini_free(config);
}

// Test 3: Die Rekursions-Falle prüfen
Test(INI_Härtetest, Tiefe_Rekursions_Falle) {
    ini_t *config = ini_load("test_data/key_definition_could_start_deep_recursion.ini");
    cr_assert_not_null(config, "Parser ist bei Rekursions-Test abgestürzt!");
    ini_free(config);
}

