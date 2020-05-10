import { Member } from './member';

export type typename = string;
export class Struct {

    private members: Member[];

    public constructor(private structStr: string) {

    }

    public toString(): string {
        return this.structStr;
    }

}
