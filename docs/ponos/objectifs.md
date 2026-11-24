# Objectifs

## Finalité
L'application est un bot Discord conçu pour gérer les droits d'accès et vérifier les réponses des participants lors d'une formation. Elle permet aux organisateurs de structurer les accès aux contenus et aux participants de soumettre leurs réponses pour validation, tout en assurant une gestion centralisée des autorisations.

## Utilisateurs cibles
- **Organisateurs de la formation** : Gestion des rôles, configuration des cours, validation des réponses.
- **Participants** : Soumission de réponses, vérification de leurs droits d'accès, notifications.

## Fonctionnalités clés
- Gestion des rôles et droits d'accès (assignation automatique ou manuelle).
- Vérification des réponses soumises par les participants (validation automatisée ou manuelle).
- Notifications en temps réel pour les participants et les organisateurs.
- Interface de gestion simplifiée pour les organisateurs (dashboard).

## Périmètre de la première version
- Implémentation du système de gestion des rôles et des droits d'accès.
- Mécanisme de soumission et de vérification des réponses.
- Notifications basiques via le canal Discord.
- Interface de gestion minimale pour les organisateurs (via un dashboard React).

## Hors-périmètre explicite
- Aucune intégration externe (API, services cloud) n'est requise.
- Fonctionnalités avancées comme l'analyse des performances ou la gestion de plusieurs formations simultanément ne sont pas incluses dans la première version.

## Critères de réussite
- Le bot assigne correctement les rôles en fonction des validations des réponses.
- Les participants reçoivent des notifications claires après soumission ou validation.
- Les organisateurs peuvent gérer les cours et les rôles via l'interface.
- Le système fonctionne sans erreurs sur les environnements Discord standard.

## Hypothèses
- La structure de la formation (cours, échéances) est définie à l'avance et ne nécessite pas de flexibilité dynamique.
- Les interactions du bot sont limitées aux commandes Discord et aux notifications directes.
- La base de données Postgres est optimisée pour gérer les relations entre utilisateurs, rôles et réponses.