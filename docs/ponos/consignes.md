# Consignes

## Code propre et lisible
- Utilisez Prettier pour formatter le code automatiquement (configurations standard pour React et FastAPI).
- Maintenez une indentation de 2 espaces, des noms de variables explicites, et des commentaires lorsqu'ils apportent une valeur ajoutée.
- Priorisez la lisibilité des fonctions (une fonction = une action) et la cohérence des noms de variables/constantes.

## Refactoring au fil de l'eau
- Refactorisez les blocs de code dès qu'ils deviennent plus longs que 15 lignes ou qu'ils contiennent plus d'une responsabilité.
- Supprimez le code mort régulièrement (via l'analyse de couverture de tests).
- Évitez les duplications en créant des helpers ou des services réutilisables.

## Sécurité
- **Secrets** : Utilisez des variables d'environnement pour les clés JWT et les connexions DB. Ne committez jamais de secrets dans le code.
- **Validation des entrées** : Validez toutes les données reçues (ex: format des réponses, longueur des textes) via des middleware ou des schemas (ex: Pydantic pour FastAPI).
- **Droits** : Implémentez un système de contrôle d'accès basé sur les rôles (RBAC) pour toutes les endpoints. Les administrateurs doivent être identifiés via JWT.

## Tests attendus
- **Unitaires** : Écrivez des tests isolés pour chaque fonction métier (ex: validation de réponses, assignation de rôles) avec pytest.
- **Intégration** : Testez les flux complets (ex: soumission → validation → notification) via des mocks ou des bases de données en mémoire.
- **Tests d'acceptation** : Utilisez des outils comme Cypress pour tester l'interface React (dashboard administrateur).

## Conventions de branches `type/resume-court`
- Nommez les branches selon le format `type/resume-court` :
  - `feat/panier` : Nouvelle fonctionnalité
  - `fix/login` : Correction de bug
  - `chore/docs` : Mise à jour de documentation
  - `refactor/auth` : Refactoring
  - `ci/cd` : Amélioration de la CI/CD
- Les branches devraient être mergées dans `main` après validation par une revue de code.

## Messages de commit
- Suivez la convention `type: description` :
  - `feat: ajouter la logique d'assignation de rôle`
  - `fix: corriger la validation des réponses`
  - `docs: mettre à jour la charte de design`
  - `refactor: simplifier la gestion des notifications`
  - `chore: mettre à jour les dépendances`
- Évitez les messages vagues comme "fix bug" : précisez ce que vous avez corrigé.

## Mise à jour de ces docs
- **objectifs.md** : Mettez à jour lors de changements de périmètre (ex: ajout de nouvelles fonctionnalités, suppression de limites).
- **architecture.md** : Mettez à jour pour les décisions techniques majeures (ex: changement de stack, ajout de composants).
- **charte.md** : Mettez à jour pour les changements de design ou de palette de couleurs.
- **consignes.md** : Mettez à jour pour les modifications de processus (ex: nouveaux tests, conventions de code).

## Hypothèses
- Aucune intégration externe n'est requise : le bot ne communiquera qu'avec Discord et sa base de données.
- La gestion des rôles et des réponses est centralisée dans le backend, avec un dashboard React minimaliste.
- Les tests sont limités aux fonctionnalités principales (pas de tests d'UI complexes pour le frontend).