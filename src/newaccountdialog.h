///////////////////////////////////////////////////////////////////////////////
//
// CoinVault
//
// newaccountdialog.h
//
// Copyright (c) 2013-2014 Eric Lombrozo
//
// All Rights Reserved.

#pragma once

class QLineEdit;
class QListWidget;
class QComboBox;
class QDateTimeEdit;
class QCalendarWidget;
class QPushButton;

#include <QDialog>
#include <QSet>
#include <QList>
#include <QString>

class NewAccountDialog : public QDialog
{
    Q_OBJECT

public:
    NewAccountDialog(const QList<QString>& allKeychains, const QList<QString>& selectedKeychains, QWidget* parent = nullptr);
    ~NewAccountDialog();

    QString getName() const;
    QList<QString> getKeychainNames() const { return keychainSet.toList(); }
    int getMinSigs() const;

    qint64 getCreationTime() const;

private:
    void updateSelection(const QString& keychain, int state);
    void updateMinSigs();
    void updateEnabled();

    QLineEdit* nameEdit;
    QListWidget* keychainListWidget;
    QSet<QString> keychainSet;
    QLineEdit* keychainEdit;
    QComboBox* minSigComboBox;
    QLineEdit* minSigLineEdit;

    QDateTimeEdit* creationTimeEdit;
    QCalendarWidget* calendarWidget;

    QPushButton* okButton;
};

