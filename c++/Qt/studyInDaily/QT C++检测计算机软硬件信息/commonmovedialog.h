#ifndef COMMONMOVEDIALOG_H
#define COMMONMOVEDIALOG_H

#include <QDialog>

class CommonMoveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CommonMoveDialog(QWidget *parent = 0);
    ~CommonMoveDialog();

protected:
    void mousePressEvent(QMouseEvent * event) override;
    void mouseReleaseEvent(QMouseEvent * event) override;
    void mouseMoveEvent(QMouseEvent * event) override;

protected:
    bool m_bCouldMove;
    QPoint m_MousePressedPoint;
};

#endif // COMMONMOVEDIALOG_H
